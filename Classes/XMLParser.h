//
//  XMLParser.h
//  StarForYou
//
//  Created by 任杰 on 14/10/30.
//
//

#ifndef __StarForYou__XMLParser__
#define __StarForYou__XMLParser__

#include <stdio.h>
#include <string>
#include "cocos2d.h"

class XMLParser : public cocos2d::CCObject, public cocos2d::SAXDelegator
{
public:
    static XMLParser* parseWithFile(const char *xmlFileName);
    
    static XMLParser* parseWithString(const char *content);
    
    XMLParser();
    virtual ~XMLParser();
    
    
    //从本地xml文件读取
    bool initWithFile(const char *xmlFileName);
    
    
    // 从字符中读取，可用于读取网络中的xml数据
    bool initWithString(const char *content);
    
    
    /**
     
     * 对应的xml标签开始，如：<string name="alex">,name为string的属性，如["name","alex"]
     
     */
    virtual void startElement(void *ctx, const char *name, const char **atts);
    
    
    /**
     
     * 对应xml标签结束，如 ：</string>
     
     */
    virtual void endElement(void *ctx, const char *name);
    
    
    /**
     
     * 对应xml标签文本，如：<string name="alex">Alex Zhou</string>的Alex Zhou
     
     */
    virtual void textHandler(void *ctx, const char *s, int len);
    
    cocos2d::CCString* getString(const char *key);
    
private:
    cocos2d::CCDictionary *m_pDictionary;
    std::string m_key;
    
    std::string startXMLElement;
    std::string endXMLElement;
    
};


#endif /* defined(__StarForYou__XMLParser__) */
