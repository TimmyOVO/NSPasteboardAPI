//
//  CocoaJNI.m
//  CocoaJNI
//
//  Created by OVO Timmy on 2019/12/16.
//  Copyright © 2019 OVO Timmy. All rights reserved.
//

#import "CocoaJNI.h"
#import "JNIBridge.h"
#import <Cocoa/Cocoa.h>
#import "NSPasteboardAPI.h"

typedef enum _PasteboardType {
    URL = 0,
    COLOR = 1,
    FILE_CONTENTS = 2,
    FILE_URL = 3,
    FONT = 4,
    HTML = 5,
    PDF = 6,
    PNG = 7,
    STRING = 8,
} PasteboardType;

@implementation TestCocoaJNI

@end

void JNINSPasteboard::clearContent(){
    NSPasteboard*  myPasteboard  = [NSPasteboard generalPasteboard];
    [myPasteboard clearContents];
}

std::string JNINSPasteboard::getContent(int type){
    NSPasteboard*  generalPasteboard  = [NSPasteboard generalPasteboard];
    NSString* content;
    switch (type) {
        case FILE_URL:
            content = [generalPasteboard stringForType:NSPasteboardTypeFileURL];
            break;
        case STRING:
            content = [generalPasteboard stringForType:NSPasteboardTypeString];
        default:
            break;
    }
    if(content == nullptr){
        return "";
    }
    return [content UTF8String];
}

void JNINSPasteboard::writeString(std::string s){
    NSPasteboard*  generalPasteboard  = [NSPasteboard generalPasteboard];
    NSString* input = [NSString stringWithUTF8String:s.c_str()];
    //clear pasteboard first
    clearContent();
    //write string
    [generalPasteboard writeObjects:[NSArray arrayWithObject:input]];
    
}

void JNINSPasteboard::writeFileURL(std::string url){
    NSPasteboard*  generalPasteboard  = [NSPasteboard generalPasteboard];
    NSString* input = [NSString stringWithUTF8String:url.c_str()];
    NSURL* nsurl = [NSURL fileURLWithPath:input];
    // clear pasteboard
    clearContent();
    [generalPasteboard writeObjects:[NSArray arrayWithObject:nsurl]];
}

void JNINSPasteboard::writeFilesURL(std::list<std::string> urls){
    NSPasteboard*  generalPasteboard  = [NSPasteboard generalPasteboard];
    NSMutableArray* u = [NSMutableArray arrayWithCapacity:urls.size()];
    for(std::string url : urls){
        NSString* cc = [NSString stringWithUTF8String:url.c_str()];
        [u addObject:[NSURL fileURLWithPath:cc]];
    }
    clearContent();
    [generalPasteboard writeObjects:u];
}
