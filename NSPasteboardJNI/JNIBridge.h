//
//  JNIBridge.h
//  TestCocoaJNI
//
//  Created by OVO Timmy on 2019/12/16.
//  Copyright © 2019 OVO Timmy. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#ifndef JNIBridge_h
#define JNIBridge_h

using namespace std;

#endif /* JNIBridge_h */

class JNINSPasteboard {
public:
    static void clearContent();
    static string getContent(int i);
    static void writeString(string s);
    static void writeFileURL(string url);
};
