//
//  JNIBridge.h
//  TestCocoaJNI
//
//  Created by OVO Timmy on 2019/12/16.
//  Copyright © 2019 OVO Timmy. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <list>
#include "NSPasteboardAPI.h"

#ifndef JNIBridge_h
#define JNIBridge_h

#endif /* JNIBridge_h */

class JNINSPasteboard {
public:
    static void clearContent();
    static std::string getContent(int i);
    static void writeString(std::string s);
    static void writeFileURL(std::string url);
    static void writeFilesURL(std::list<std::string> urls);
};

/*
 * Class:     com_github_timmyovo_nspasteboard_NSPasteboardAPI
 * Method:    clearContent
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_github_timmyovo_nspasteboard_NSPasteboardAPI_clearContent
 (JNIEnv* env, jclass){
     JNINSPasteboard::clearContent();
 }

/*
 * Class:     com_github_timmyovo_nspasteboard_NSPasteboardAPI
 * Method:    getClipboardContent
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_github_timmyovo_nspasteboard_NSPasteboardAPI_getClipboardContent
 (JNIEnv* env, jclass, jint type){
     return env->NewStringUTF(JNINSPasteboard::getContent(type).c_str());
 }

/*
 * Class:     com_github_timmyovo_nspasteboard_NSPasteboardAPI
 * Method:    writeClipboardString
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_github_timmyovo_nspasteboard_NSPasteboardAPI_writeClipboardString
 (JNIEnv* env, jclass, jstring s){
     const char* arg = env->GetStringUTFChars(s, 0);
     JNINSPasteboard::writeString(arg);
 }

/*
 * Class:     com_github_timmyovo_nspasteboard_NSPasteboardAPI
 * Method:    writeClipboardFileURL
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_github_timmyovo_nspasteboard_NSPasteboardAPI_writeClipboardFileURL
 (JNIEnv* env, jclass, jstring url){
     const char* arg = env->GetStringUTFChars(url, 0);
     JNINSPasteboard::writeFileURL(arg);
 }

JNIEXPORT void JNICALL Java_com_github_timmyovo_nspasteboard_NSPasteboardAPI_writeClipboardFilesURL
 (JNIEnv *env, jclass, jobjectArray urls) {
     std::list<std::string> nativeUrls = {};
     for (int i =0 ; i< env->GetArrayLength(urls); i++ ){
         jstring jstr = (jstring)env->GetObjectArrayElement(urls, (jsize)i);
         const char* cstr = env->GetStringUTFChars(jstr, 0);
         nativeUrls.push_front(cstr);
         env->ReleaseStringUTFChars(jstr, cstr);
     }
     JNINSPasteboard::writeFilesURL(nativeUrls);
 }
