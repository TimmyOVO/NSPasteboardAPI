/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class NSPasteboardAPI */

#include "JNIBridge.h"

#ifndef _Included_NSPasteboardAPI
#define _Included_NSPasteboardAPI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     NSPasteboardAPI
 * Method:    clearContent
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_NSPasteboardAPI_clearContent
 (JNIEnv *, jclass){
     JNINSPasteboard::clearContent();
 }

/*
 * Class:     NSPasteboardAPI
 * Method:    getClipboardContent
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_NSPasteboardAPI_getClipboardContent
 (JNIEnv* env, jclass, jint type){
     return env->NewStringUTF(JNINSPasteboard::getContent(type).c_str());
 }

/*
 * Class:     NSPasteboardAPI
 * Method:    writeClipboardString
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_NSPasteboardAPI_writeClipboardString
 (JNIEnv* env, jclass, jstring s){
     const char* arg = env->GetStringUTFChars(s, 0);
     JNINSPasteboard::writeString(arg);
 }

/*
 * Class:     NSPasteboardAPI
 * Method:    writeClipboardFileURL
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_NSPasteboardAPI_writeClipboardFileURL
 (JNIEnv* env, jclass, jstring url){
     const char* arg = env->GetStringUTFChars(url, 0);
     JNINSPasteboard::writeString(arg);
 }

#ifdef __cplusplus
}
#endif
#endif