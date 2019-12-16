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

string JNINSPasteboard::getContent(int type){
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
    return [content UTF8String];
}

void JNINSPasteboard::writeString(string s){
    NSPasteboard*  generalPasteboard  = [NSPasteboard generalPasteboard];
    [generalPasteboard setString:[NSString stringWithUTF8String:s.c_str()] forType:NSPasteboardTypeString];
}

void JNINSPasteboard::writeFileURL(string url){
    NSPasteboard*  generalPasteboard  = [NSPasteboard generalPasteboard];
    [generalPasteboard setString:[NSString stringWithUTF8String:url.c_str()] forType:NSPasteboardTypeFileURL];
}
