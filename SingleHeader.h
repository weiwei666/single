//
//  SingleHeader.h
//  
//
//  Created by weiwei on 15/9/16.
//  Copyright (c) 2015年 *****. All rights reserved.
//

#ifndef Single_Header_h
#define Single_Header_h

// .h文件
#define SingletonH(name) + (instancetype)shared##name;

// .m文件
#define SingletonM(name) \
static id _instance; \
\
+ (id)allocWithZone:(struct _NSZone *)zone \
{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
    _instance = [super allocWithZone:zone]; \
}); \
    return _instance; \
} \
\
+ (instancetype)shared##name \
{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
    _instance = [[self alloc] init]; \
}); \
    return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
    return _instance; \
}

#endif
