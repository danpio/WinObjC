//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "XIBObject.h"
#include "NIBWriter.h"
#include "XIBObjectTypes.h"
#include "UIView.h"
#include "UIViewController.h"
#include "UIProxyObject.h"
#include "UIColor.h"
#include "UIButton.h"
#include "UIFont.h"
#include "UIRuntimeEventConnection.h"
#include "UIRuntimeOutletConnection.h"
#include "UICustomResource.h"
#include "UIWindow.h"
#include "UIScrollView.h"
#include "UITableView.h"
#include "UINavigationBar.h"
#include "UINavigationItem.h"
#include "UIBarButtonItem.h"
#include "UIImageView.h"
#include "UILabel.h"
#include "UIRuntimeAccessibilityConfiguration.h"
#include "UITableViewCell.h"

float screenWidth = 320.0f, screenHeight = 460.0f;

static XIBObject* findBestVariation(XIBObject* obj) {
    XIBObject* variation = NULL;
    for (auto var = obj->_variations.begin(); var != obj->_variations.end(); var++) {
        XIBObject *varObj = *var;
        XIBObject *widthClass = varObj->FindMember("widthClass");

        // TODO: A way to control this. We've decided the first widthClass=compact beats out all others, 
        // since we're expecting a phone sized screen, and "default" wins otherwise.
        if (widthClass && strcmp(widthClass->stringValue(), "compact") == 0) {
            return varObj;
        }
        else if (!variation) {
            variation = varObj;
        }
    }

    return variation;
}

XIBMember::XIBMember()
{
    _name = NULL;
    _refId = NULL;
    _obj = NULL;
}

xibList XIBObject::_allObjs;

void XIBObject::AddOutputMember(NIBWriter *writer, const char *keyName, XIBObject *obj)
{
    XIBMember *pNewMember = new XIBMember();
    XIBObject *addObj = writer->AddOutputObject(obj);

    pNewMember->_name = keyName;
    pNewMember->_obj = addObj;
    pNewMember->_refId = NULL;
    _outputMembers.push_back(pNewMember);
    
}

bool XIBObject::NeedsSerialization() 
{
    return true;
}

bool XIBObject::isNil()
{
    return false;
}

int XIBObject::intValue() 
{
    assert(0);
    return -1;
}

const char *XIBObject::stringValue() {
    assert(0);
    return NULL;
}

float XIBObject::floatValue() 
{
    assert(0);
    return -1;
}

bool XIBObject::EqualToString(const char *str)
{
    return false;
}

const char *XIBObject::ClassName()
{
    if ( _className ) return _className;
    return "";
}

void XIBObject::SetSwappedClassName(const char *pName)
{
    _swappedClassName = pName;
}

const char *XIBObject::SwappedClassName()
{
    return _swappedClassName;
}

const char *getNodeAttrib(pugi::xml_node node, const char *name)
{
    const char* val = node.attribute(name).value();
    return strlen(val) > 0 ? val : NULL;
}

const char *XIBObject::getAttrib(const char *name)
{
    XIBObject *bestVar = findBestVariation(this);
    const char* variation = NULL;

    if (bestVar) {
        variation = bestVar->getAttrib(name);
    }

    if (variation) return variation;

    return getNodeAttrib(_node, name);
}

XIBObject::XIBObject()
{
    _parent = NULL;
    _node = pugi::xml_node();
    _className = NULL;
    _id = NULL;
    _swappedClassName = NULL;
    _outputClassName = NULL;
    _needsConversion = true;
    _converter = NULL;
    _ignoreUIObject = false;
    _isStory = false;
    _connectedObjects = NULL;
}

void XIBObject::ScanXIBNode(pugi::xml_node node)
{
    _allObjs.push_back(this);

    _node = node;
    _needsConversion = true;
    _className = getAttrib("class");
    _id = getAttrib("id");
    _swappedClassName = NULL;
    _outputClassName = NULL;
    _converter = NULL;

    //  Go through all child nodes
    for (pugi::xml_node curNode : _node.children()) {
        if (curNode.type() == pugi::xml_node_type::node_element) {
            const char *keyName = getNodeAttrib(curNode, "key");

            if ( strcmp(curNode.name(), "object") == 0 ) {
                XIBObject *subObj = NULL;
                const char *className = curNode.attribute("class").value();
                if ( strcmp(className, "NSDictionary") == 0 || strcmp(className, "NSMutableDictionary") == 0 ) {
                    subObj = new XIBDictionary(curNode);
                } else if ( strcmp(className, "NSArray") == 0 || strcmp(className, "NSMutableArray") == 0 ) {
                    subObj = new XIBArray(curNode);
                } else {
                    subObj = ObjectConverter::ConverterForObject(className, curNode);
                }
                AddMember(keyName, subObj);
                subObj->_parent = this;
            } else if ( strcmp(curNode.name(), "reference") == 0 ) {
                const char *refId = getNodeAttrib(curNode, "ref");

                XIBMember *newMember = new XIBMember();
                newMember->_name = keyName;
                newMember->_refId = refId;

                _members.push_back(newMember);
            } else if ( strcmp(curNode.name(), "string") == 0 ) {
                XIBObject *str = new XIBObjectString(curNode.child_value());
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "integer") == 0 ) {
                XIBObject *str = new XIBObjectInt(atoi(curNode.attribute("value").value()));
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "int") == 0 ) {
                XIBObject *str = new XIBObjectInt(atoi(curNode.child_value()));
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "bool") == 0 ) {
                XIBObject *str = new XIBObjectBool(curNode);
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "boolean") == 0 ) {
                XIBObject *str = new XIBObjectBool(curNode);
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "bytes") == 0 ) {
                XIBObject *str = new XIBObjectData(curNode.child_value());
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "nil") == 0 ) {
                XIBObject *str = new XIBObjectNil();
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "real") == 0 ) {
                XIBObject *str = new XIBObjectReal(curNode);
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "float") == 0 ) {
                XIBObject *str = new XIBObjectFloat(curNode);
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "double") == 0 ) {
                XIBObject *str = new XIBObjectDouble(curNode);
                str->_id = getNodeAttrib(curNode, "id");
                _allObjs.push_back(str);
                AddMember(keyName, str);
            } else if ( strcmp(curNode.name(), "array") == 0 ) {
                XIBObject *subObj = new XIBArray(curNode);
                AddMember(keyName, subObj);
                subObj->_parent = this;
            } else if ( strcmp(curNode.name(), "dictionary") == 0 ) {
                XIBObject *subObj = new XIBDictionary(curNode);
                AddMember(keyName, subObj);
                subObj->_parent = this;
            } else {
                assert(0);
            }
        }
    }
}

void XIBObject::ScanStoryObjects(pugi::xml_node node)
{
    _allObjs.push_back(this);
    _node = node;
    _needsConversion = true;
    _swappedClassName = NULL;
    _outputClassName = NULL;
    _converter = NULL;
    _id = getAttrib("id");
    _className = node.name();
    _isStory = true;

    //  Go through all child nodes
    for (pugi::xml_node curNode : _node.children()) {
        if (curNode.type() == pugi::xml_node_type::node_element) {
            XIBObject *subObj = NULL;
            subObj = ObjectConverter::ConverterForStoryObject(curNode.name(), curNode);

            // Variations are special case that selectively override the node's objects, or mask items out of an array
            if (strcmp(subObj->ClassName(), "variation") == 0) {
                // At the time of writing, size classes are of the form (width|height)Class=(regular|compact)(-(width|height)Class=(regular|compact))*
                std::string key(subObj->getAttrib("key"));
                while (1) {
                    auto hcpos = key.find('=');
                    if (hcpos == std::string::npos) {
                        break;
                    }
                    auto className = key.substr(0, hcpos);
                    auto hdpos = key.find('-');
                    if (hdpos == std::string::npos) {
                        hdpos = key.length();
                    }
                    hcpos++; // Skip the '='

                    // Here come some memory leaks. But someone decided const char* for all string storage was the way to go. 
                    char *cClassName = new char[className.length()+1];
                    std::string classStr = key.substr(hcpos, hdpos - hcpos);
                    char *cClassStr = new char[classStr.length()+1];
                    
                    memcpy(cClassName, className.c_str(), className.length() + 1);
                    memcpy(cClassStr, classStr.c_str(), classStr.length() + 1);

                    subObj->AddMember(cClassName, new XIBObjectString(cClassStr));
                    if (hdpos == key.length()) {
                        break;
                    }
                    key = key.substr(hdpos+1);
                }
                _variations.push_back(subObj);
            } 

            subObj->_parent = this;
            const char *keyName = getNodeAttrib(curNode, "key");
            AddMember(keyName, subObj);

        }
    }
}

void XIBObject::WriteData(NIBWriter *writer)
{
    writer->WriteByte(NIBOBJ_UID);
    writer->WriteBytes(&_outputObjectIdx, 4);
}

void XIBObject::AddMember(const char *keyName, XIBObject *member)
{
    for ( memberList::iterator cur = _members.begin(); cur != _members.end(); cur ++ ) {
        XIBMember *curMember = (*cur);

        if ( curMember->_obj == member ) {
            if ( curMember->_name == keyName ) {
                return;
            }
            if ( curMember->_name && keyName ) {
                if ( strcmp(curMember->_name, keyName) == 0 ) {
                    return;
                }
            }
        }
    }

    XIBMember *newMember = new XIBMember();
    newMember->_name = keyName;
    newMember->_obj = member;

    _members.push_back(newMember);
}

XIBObject *XIBObject::ApplyVariation(XIBObject *variation)
{
    if (variation) {
        return variation;
    } else {
        return this;
    }
}

XIBObject *XIBObject::FindMember(char *keyName)
{
    XIBObject *bestVar = findBestVariation(this);
    XIBObject* variation = NULL;

    if (bestVar) {
        for (auto i = bestVar->_members.begin(); i != bestVar->_members.end(); i++) {
            if ((*i)->_obj->getAttrib("key") && strcmp((*i)->_obj->getAttrib("key"), keyName) == 0) {
                variation = (*i)->_obj;
                break;
            }
        }
    }

    memberList::iterator cur = _members.begin();
    for (; cur != _members.end(); cur ++ ) {
        XIBMember *member = *cur;
        if ( member->_name && strcmp(member->_name, keyName) == 0 ) {
            if (member->_obj) {
                return member->_obj->ApplyVariation(variation);
            }
        }
    }

    // TODO: If the object doesn't exist, but a variation does, do we return it?
    return NULL;
}

XIBObject *XIBObject::FindMemberClass(char *className)
{
    XIBObject *bestVar = findBestVariation(this);
    XIBObject* variation = NULL;

    if (bestVar) {
        for (auto i = bestVar->_members.begin(); i != bestVar->_members.end(); i++) {
            if ((*i)->_obj->_className && strcmp((*i)->_obj->_className, "mask") == 0) {
                auto classKey = (*i)->_obj->getAttrib("key");
                if (classKey && (strcmp(classKey, className) == 0)) {
                    variation = (*i)->_obj;
                    break;
                }
            }
        }
    }

    memberList::iterator cur = _members.begin();
    for (; cur != _members.end(); cur ++ ) {
        XIBMember *member = *cur;
        if ( member->_obj->_className && strcmp(member->_obj->_className, className) == 0 ) {
            if( member->_obj ) {
                return member->_obj->ApplyVariation(variation);
            }
        }
    }

    // TODO: If the object doesn't exist, but a variation does, do we return it?
    return NULL;
}

CGSize XIBObject::GetSize(char *pPropName, float defaultWidth, float defaultHeight)
{
    CGSize ret;

    ret.width = defaultWidth;
    ret.height = defaultHeight;

    XIBObject *pObj = FindMember(pPropName);
    
    if ( pObj ) {
        const char *pStr = pObj->stringValue();

        sscanf(pStr, "{%f, %f}", &ret.width, &ret.height);
    }

    return ret;
}

const char *XIBObject::GetString(char *pPropName, char *defaultValue)
{
    XIBObject *pObj = FindMember(pPropName);
    
    if ( pObj ) {
        const char *pStr = pObj->stringValue();

        if ( pStr ) return pStr;
        return "";
    }

    return defaultValue;
}

int XIBObject::GetInt(char *pPropName, int defaultValue)
{
    XIBObject *pObj = FindMember(pPropName);
    
    if ( pObj ) {
        return pObj->intValue();
    }

    return defaultValue;
}

bool XIBObject::GetBool(char *pPropName, bool defaultValue)
{
    XIBObject *pObj = FindMember(pPropName);
    
    if ( pObj ) {
        return pObj->intValue() == 1;
    }

    return defaultValue;
}

void XIBObject::AddSize(NIBWriter *writer, char *pPropName, CGSize size)
{
    char *dataOut = (char *) malloc(sizeof(CGSize) + 1);
    dataOut[0] = 6;
    memcpy(&dataOut[1], &size, sizeof(CGSize));
    AddOutputMember(writer, strdup(pPropName), new XIBObjectDataWriter(dataOut, sizeof(CGSize) + 1));
}

void XIBObject::AddPoint(NIBWriter *writer, char *pPropName, UIPoint pt)
{
    char *dataOut = (char *) malloc(sizeof(UIPoint) + 1);
    dataOut[0] = 6;
    memcpy(&dataOut[1], &pt, sizeof(UIPoint));
    AddOutputMember(writer, strdup(pPropName), new XIBObjectDataWriter(dataOut, sizeof(UIPoint) + 1));
}

void XIBObject::AddRect(NIBWriter *writer, char *pPropName, UIRect pt)
{
    char *dataOut = (char *) malloc(sizeof(UIRect) + 1);
    dataOut[0] = 6;
    memcpy(&dataOut[1], &pt, sizeof(UIRect));
    AddOutputMember(writer, strdup(pPropName), new XIBObjectDataWriter(dataOut, sizeof(UIRect) + 1));
}

void XIBObject::AddString(NIBWriter *writer, char *pPropName, const char *str)
{
    AddOutputMember(writer, strdup(pPropName), new XIBObjectString(str));
}

void XIBObject::AddMutableString(NIBWriter *writer, char *pPropName, char *str)
{
    XIBObject *out = new XIBObjectString(str);
    out->_className = "NSMutableString";
    AddOutputMember(writer, strdup(pPropName), out);
}

void XIBObject::AddInt(NIBWriter *writer, char *pPropName, int val)
{
    AddOutputMember(writer, strdup(pPropName), new XIBObjectInt(val));
}

void XIBObject::AddBool(NIBWriter *writer, char *pPropName, bool val)
{
    AddOutputMember(writer, strdup(pPropName), new XIBObjectBool(val));
}

void XIBObject::ResolveReferences()
{
    memberList::iterator cur = _members.begin();
    for (; cur != _members.end(); cur ++ ) {
        XIBMember *member = *cur;
        if ( member->_refId != NULL ) {
            member->_obj = findReference(member->_refId);
        }
    }
}

XIBObject *XIBObject::findReference(const char *id)
{
    xibList::iterator cur = _allObjs.begin();

    for (; cur != _allObjs.end(); cur ++ ) {
        if ( (*cur)->_id == NULL ) continue;
        if ( strcmp((*cur)->_id, id) == 0 ) return (*cur);
    }

    return NULL;
}

void XIBObject::ParseAllXIBMembers()
{
    xibList::iterator cur = _allObjs.begin();

    for (; cur != _allObjs.end(); cur ++ ) {
        (*cur)->ResolveReferences();
    }

    cur = _allObjs.begin();

    for (; cur != _allObjs.end(); cur ++ ) {
        (*cur)->InitFromXIB((*cur));
    }

    cur = _allObjs.begin();

    for (; cur != _allObjs.end(); cur ++ ) {
        (*cur)->Awaken();
    }
}

void XIBObject::ParseAllStoryMembers()
{
    xibList::iterator cur = _allObjs.begin();

    for (; cur != _allObjs.end(); cur ++ ) {
        (*cur)->ResolveReferences();
    }

    cur = _allObjs.begin();

    for (; cur != _allObjs.end(); cur ++ ) {
        (*cur)->InitFromStory((*cur));
    }

    cur = _allObjs.begin();

    for (; cur != _allObjs.end(); cur ++ ) {
        (*cur)->Awaken();
    }
}

void XIBObject::EmitObject(NIBWriter *writer)
{
    if ( !_needsConversion ) return;
    _outputMembers.clear();

    ConvertStaticMappings(writer, this);
}

void XIBObject::InitFromXIB(XIBObject *obj)
{
}
void XIBObject::InitFromStory(XIBObject *obj)
{
}
void XIBObject::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
}
void XIBObject::Awaken()
{
}
