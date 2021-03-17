#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class SharedLoggerLevel, SharedKotlinEnum<E>, SharedKotlinArray<T>, SharedKVStore, SharedStep, SharedBookingState, SharedBookingStateMachine, SharedSerializableKVStore, SharedFlow, SharedDriverState, SharedAppFactory, SharedBookingFlow, SharedDropOffUIState, SharedIdleUIState, SharedPickUpUIState, SharedLoginReq, SharedLoginResp, SharedLoginErrUIState, SharedLoginPageUIState, SharedLoginFlow, SharedKotlinx_serialization_coreSerializersModule, SharedKotlinx_serialization_coreSerialKind, SharedKotlinNothing;

@protocol SharedKotlinComparable, SharedListener, SharedStream, SharedSubject, SharedKSerializable, SharedUIState, SharedDriverStateRepo, SharedKotlinx_serialization_coreKSerializer, SharedLoginApi, SharedLoginNavigator, SharedLoginApiDep, SharedKotlinIterator, SharedKotlinx_serialization_coreEncoder, SharedKotlinx_serialization_coreSerialDescriptor, SharedKotlinx_serialization_coreSerializationStrategy, SharedKotlinx_serialization_coreDecoder, SharedKotlinx_serialization_coreDeserializationStrategy, SharedKotlinx_serialization_coreCompositeEncoder, SharedKotlinAnnotation, SharedKotlinx_serialization_coreCompositeDecoder, SharedKotlinx_serialization_coreSerializersModuleCollector, SharedKotlinKClass, SharedKotlinKDeclarationContainer, SharedKotlinKAnnotatedElement, SharedKotlinKClassifier;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

__attribute__((swift_name("KotlinBase")))
@interface SharedBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end;

@interface SharedBase (SharedBaseCopying) <NSCopying>
@end;

__attribute__((swift_name("KotlinMutableSet")))
@interface SharedMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((swift_name("KotlinMutableDictionary")))
@interface SharedMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

@interface NSError (NSErrorSharedKotlinException)
@property (readonly) id _Nullable kotlinException;
@end;

__attribute__((swift_name("KotlinNumber")))
@interface SharedNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end;

__attribute__((swift_name("KotlinByte")))
@interface SharedByte : SharedNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end;

__attribute__((swift_name("KotlinUByte")))
@interface SharedUByte : SharedNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end;

__attribute__((swift_name("KotlinShort")))
@interface SharedShort : SharedNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end;

__attribute__((swift_name("KotlinUShort")))
@interface SharedUShort : SharedNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end;

__attribute__((swift_name("KotlinInt")))
@interface SharedInt : SharedNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end;

__attribute__((swift_name("KotlinUInt")))
@interface SharedUInt : SharedNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end;

__attribute__((swift_name("KotlinLong")))
@interface SharedLong : SharedNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end;

__attribute__((swift_name("KotlinULong")))
@interface SharedULong : SharedNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end;

__attribute__((swift_name("KotlinFloat")))
@interface SharedFloat : SharedNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end;

__attribute__((swift_name("KotlinDouble")))
@interface SharedDouble : SharedNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end;

__attribute__((swift_name("KotlinBoolean")))
@interface SharedBoolean : SharedNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Greeting")))
@interface SharedGreeting : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)greeting __attribute__((swift_name("greeting()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform")))
@interface SharedPlatform : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly) NSString *platform __attribute__((swift_name("platform")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Logger")))
@interface SharedLogger : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)errorMsg:(NSString *)msg __attribute__((swift_name("error(msg:)")));
- (void)infoMsg:(NSString *)msg __attribute__((swift_name("info(msg:)")));
- (void)logLevel:(SharedLoggerLevel *)level msg:(NSString *)msg __attribute__((swift_name("log(level:msg:)")));
- (void)warningMsg:(NSString *)msg __attribute__((swift_name("warning(msg:)")));
@end;

__attribute__((swift_name("KotlinComparable")))
@protocol SharedKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end;

__attribute__((swift_name("KotlinEnum")))
@interface SharedKotlinEnum<E> : SharedBase <SharedKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Logger.Level")))
@interface SharedLoggerLevel : SharedKotlinEnum<SharedLoggerLevel *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SharedLoggerLevel *info __attribute__((swift_name("info")));
@property (class, readonly) SharedLoggerLevel *warning __attribute__((swift_name("warning")));
@property (class, readonly) SharedLoggerLevel *error __attribute__((swift_name("error")));
+ (SharedKotlinArray<SharedLoggerLevel *> *)values __attribute__((swift_name("values()")));
@end;

__attribute__((swift_name("Stream")))
@protocol SharedStream
@required
- (void)disposeListener:(id<SharedListener>)listener __attribute__((swift_name("dispose(listener:)")));
- (void)listenListener:(id<SharedListener>)listener __attribute__((swift_name("listen(listener:)")));
@property id _Nullable lastValue __attribute__((swift_name("lastValue")));
@end;

__attribute__((swift_name("Subject")))
@protocol SharedSubject <SharedStream>
@required
- (void)nextV:(id _Nullable)v __attribute__((swift_name("next(v:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BehaviourSubject")))
@interface SharedBehaviourSubject<T> : SharedBase <SharedSubject>
- (instancetype)initWithDefault:(T _Nullable)default_ __attribute__((swift_name("init(default:)"))) __attribute__((objc_designated_initializer));
- (void)disposeListener:(id<SharedListener>)listener __attribute__((swift_name("dispose(listener:)")));
- (void)listenListener:(id<SharedListener>)listener __attribute__((swift_name("listen(listener:)")));
- (void)nextFn:(T _Nullable (^)(T _Nullable))fn __attribute__((swift_name("next(fn:)")));
- (void)nextV:(T _Nullable)v __attribute__((swift_name("next(v:)")));
@property T _Nullable lastValue __attribute__((swift_name("lastValue")));
@end;

__attribute__((swift_name("Listener")))
@protocol SharedListener
@required
- (void)onDispose __attribute__((swift_name("onDispose()")));
- (void)onNextV:(id _Nullable)v __attribute__((swift_name("onNext(v:)")));
@end;

__attribute__((swift_name("KSerializable")))
@protocol SharedKSerializable
@required
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KVStore")))
@interface SharedKVStore : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString * _Nullable)getKey:(NSString *)key __attribute__((swift_name("get(key:)")));
- (void)setKey:(NSString *)key value:(NSString *)value __attribute__((swift_name("set(key:value:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SerializableKVStore")))
@interface SharedSerializableKVStore : SharedBase
- (instancetype)initWithKvStore:(SharedKVStore *)kvStore __attribute__((swift_name("init(kvStore:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)getKey:(NSString *)key __attribute__((swift_name("get(key:)")));
- (void)setKey:(NSString *)key value:(id<SharedKSerializable>)value __attribute__((swift_name("set(key:value:)")));
@property (readonly) SharedKVStore *kvStore __attribute__((swift_name("kvStore")));
@end;

__attribute__((swift_name("UIState")))
@protocol SharedUIState
@required
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EmptyUIState")))
@interface SharedEmptyUIState : SharedBase <SharedUIState>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)emptyUIState __attribute__((swift_name("init()")));
@end;

__attribute__((swift_name("Flow")))
@interface SharedFlow : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)dispose __attribute__((swift_name("dispose()")));
- (id<SharedStream>)getStream __attribute__((swift_name("getStream()")));
- (void)doInit __attribute__((swift_name("doInit()")));
- (void)postUiState:(id<SharedUIState>)uiState __attribute__((swift_name("post(uiState:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BookingState")))
@interface SharedBookingState : SharedBase
- (instancetype)initWithId:(int32_t)id steps:(NSArray<SharedStep *> *)steps current:(int32_t)current __attribute__((swift_name("init(id:steps:current:)"))) __attribute__((objc_designated_initializer));
- (int32_t)component1 __attribute__((swift_name("component1()")));
- (NSArray<SharedStep *> *)component2 __attribute__((swift_name("component2()")));
- (int32_t)component3 __attribute__((swift_name("component3()")));
- (SharedBookingState *)doCopyId:(int32_t)id steps:(NSArray<SharedStep *> *)steps current:(int32_t)current __attribute__((swift_name("doCopy(id:steps:current:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t current __attribute__((swift_name("current")));
@property (readonly) int32_t id __attribute__((swift_name("id")));
@property (readonly) NSArray<SharedStep *> *steps __attribute__((swift_name("steps")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BookingStateMachine")))
@interface SharedBookingStateMachine : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)addNewBookingId:(int32_t)id pickup:(NSString *)pickup stuff:(NSString *)stuff dropOff:(NSString *)dropOff __attribute__((swift_name("addNewBooking(id:pickup:stuff:dropOff:)")));
- (BOOL)completeStep __attribute__((swift_name("completeStep()")));
@property (readonly) id<SharedStream> stream __attribute__((swift_name("stream")));
@end;

__attribute__((swift_name("Step")))
@interface SharedStep : SharedBase
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Step.DropOff")))
@interface SharedStepDropOff : SharedStep
- (instancetype)initWithDropOff:(NSString *)dropOff __attribute__((swift_name("init(dropOff:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *dropOff __attribute__((swift_name("dropOff")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Step.PickUp")))
@interface SharedStepPickUp : SharedStep
- (instancetype)initWithPickup:(NSString *)pickup stuff:(NSString *)stuff __attribute__((swift_name("init(pickup:stuff:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *pickup __attribute__((swift_name("pickup")));
@property (readonly) NSString *stuff __attribute__((swift_name("stuff")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AppFactory")))
@interface SharedAppFactory : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly) SharedBookingStateMachine *bookingStateMachine __attribute__((swift_name("bookingStateMachine")));
@property (readonly) SharedSerializableKVStore *kvStore __attribute__((swift_name("kvStore")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BookingFlow")))
@interface SharedBookingFlow : SharedFlow <SharedListener>
- (instancetype)initWithStateMachine:(SharedBookingStateMachine *)stateMachine driverStateRepo:(id<SharedDriverStateRepo>)driverStateRepo __attribute__((swift_name("init(stateMachine:driverStateRepo:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (void)dispose __attribute__((swift_name("dispose()")));
- (void)doInit __attribute__((swift_name("doInit()")));
- (void)onNextV:(SharedBookingState *)v __attribute__((swift_name("onNext(v:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DriverState")))
@interface SharedDriverState : SharedBase <SharedKSerializable>
- (instancetype)initWithOrdersCompleted:(int32_t)ordersCompleted __attribute__((swift_name("init(ordersCompleted:)"))) __attribute__((objc_designated_initializer));
- (int32_t)component1 __attribute__((swift_name("component1()")));
- (SharedDriverState *)doCopyOrdersCompleted:(int32_t)ordersCompleted __attribute__((swift_name("doCopy(ordersCompleted:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t ordersCompleted __attribute__((swift_name("ordersCompleted")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DriverState.Companion")))
@interface SharedDriverStateCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<SharedKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end;

__attribute__((swift_name("DriverStateRepo")))
@protocol SharedDriverStateRepo
@required
- (SharedDriverState *)getDriverState __attribute__((swift_name("getDriverState()")));
- (void)setDriverStateState:(SharedDriverState *)state __attribute__((swift_name("setDriverState(state:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DriverStateRepoImpl")))
@interface SharedDriverStateRepoImpl : SharedBase <SharedDriverStateRepo>
- (instancetype)initWithKvStore:(SharedSerializableKVStore *)kvStore __attribute__((swift_name("init(kvStore:)"))) __attribute__((objc_designated_initializer));
- (SharedDriverState *)getDriverState __attribute__((swift_name("getDriverState()")));
- (void)setDriverStateState:(SharedDriverState *)state __attribute__((swift_name("setDriverState(state:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DriverStateRepoImpl.Companion")))
@interface SharedDriverStateRepoImplCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BookingFactory")))
@interface SharedBookingFactory : SharedBase
- (instancetype)initWithAppFactory:(SharedAppFactory *)appFactory __attribute__((swift_name("init(appFactory:)"))) __attribute__((objc_designated_initializer));
- (SharedBookingFlow *)bookingFlow __attribute__((swift_name("bookingFlow()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DropOffUIState")))
@interface SharedDropOffUIState : SharedBase <SharedUIState>
- (instancetype)initWithDropOff:(NSString *)dropOff onDropOff:(void (^)(void))onDropOff __attribute__((swift_name("init(dropOff:onDropOff:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (void (^)(void))component2 __attribute__((swift_name("component2()")));
- (SharedDropOffUIState *)doCopyDropOff:(NSString *)dropOff onDropOff:(void (^)(void))onDropOff __attribute__((swift_name("doCopy(dropOff:onDropOff:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *dropOff __attribute__((swift_name("dropOff")));
@property (readonly) void (^onDropOff)(void) __attribute__((swift_name("onDropOff")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IdleUIState")))
@interface SharedIdleUIState : SharedBase <SharedUIState>
- (instancetype)initWithBookingsDoneToday:(int32_t)bookingsDoneToday __attribute__((swift_name("init(bookingsDoneToday:)"))) __attribute__((objc_designated_initializer));
- (int32_t)component1 __attribute__((swift_name("component1()")));
- (SharedIdleUIState *)doCopyBookingsDoneToday:(int32_t)bookingsDoneToday __attribute__((swift_name("doCopy(bookingsDoneToday:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t bookingsDoneToday __attribute__((swift_name("bookingsDoneToday")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PickUpUIState")))
@interface SharedPickUpUIState : SharedBase <SharedUIState>
- (instancetype)initWithPickup:(NSString *)pickup stuff:(NSString *)stuff onPickup:(void (^)(void))onPickup __attribute__((swift_name("init(pickup:stuff:onPickup:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (void (^)(void))component3 __attribute__((swift_name("component3()")));
- (SharedPickUpUIState *)doCopyPickup:(NSString *)pickup stuff:(NSString *)stuff onPickup:(void (^)(void))onPickup __attribute__((swift_name("doCopy(pickup:stuff:onPickup:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) void (^onPickup)(void) __attribute__((swift_name("onPickup")));
@property (readonly) NSString *pickup __attribute__((swift_name("pickup")));
@property (readonly) NSString *stuff __attribute__((swift_name("stuff")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginFlow")))
@interface SharedLoginFlow : SharedFlow
- (instancetype)initWithApi:(id<SharedLoginApi>)api navigator:(id<SharedLoginNavigator>)navigator __attribute__((swift_name("init(api:navigator:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (void)doInit __attribute__((swift_name("doInit()")));
@end;

__attribute__((swift_name("LoginNavigator")))
@protocol SharedLoginNavigator
@required
- (void)showBookingFlow __attribute__((swift_name("showBookingFlow()")));
@end;

__attribute__((swift_name("LoginApi")))
@protocol SharedLoginApi
@required
- (void)loginReq:(SharedLoginReq *)req onSuccess:(void (^)(SharedLoginResp *))onSuccess onErr:(void (^)(NSString *))onErr __attribute__((swift_name("login(req:onSuccess:onErr:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginApiImpl")))
@interface SharedLoginApiImpl : SharedBase <SharedLoginApi>
- (instancetype)initWithApi:(id<SharedLoginApiDep>)api __attribute__((swift_name("init(api:)"))) __attribute__((objc_designated_initializer));
- (void)loginReq:(SharedLoginReq *)req onSuccess:(void (^)(SharedLoginResp *))onSuccess onErr:(void (^)(NSString *))onErr __attribute__((swift_name("login(req:onSuccess:onErr:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginReq")))
@interface SharedLoginReq : SharedBase
- (instancetype)initWithName:(NSString *)name pass:(NSString *)pass __attribute__((swift_name("init(name:pass:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (SharedLoginReq *)doCopyName:(NSString *)name pass:(NSString *)pass __attribute__((swift_name("doCopy(name:pass:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *pass __attribute__((swift_name("pass")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginReq.Companion")))
@interface SharedLoginReqCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<SharedKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginResp")))
@interface SharedLoginResp : SharedBase
- (instancetype)initWithToken:(NSString *)token name:(NSString *)name success:(BOOL)success __attribute__((swift_name("init(token:name:success:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (BOOL)component3 __attribute__((swift_name("component3()")));
- (SharedLoginResp *)doCopyToken:(NSString *)token name:(NSString *)name success:(BOOL)success __attribute__((swift_name("doCopy(token:name:success:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) BOOL success __attribute__((swift_name("success")));
@property (readonly) NSString *token __attribute__((swift_name("token")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginResp.Companion")))
@interface SharedLoginRespCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<SharedKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginErrUIState")))
@interface SharedLoginErrUIState : SharedBase <SharedUIState>
- (instancetype)initWithMsg:(NSString *)msg __attribute__((swift_name("init(msg:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (SharedLoginErrUIState *)doCopyMsg:(NSString *)msg __attribute__((swift_name("doCopy(msg:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *msg __attribute__((swift_name("msg")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginPageUIState")))
@interface SharedLoginPageUIState : SharedBase <SharedUIState>
- (instancetype)initWithGreeting:(NSString *)greeting success:(BOOL)success onLogin:(void (^)(NSString *, NSString *))onLogin onEnter:(void (^)(void))onEnter __attribute__((swift_name("init(greeting:success:onLogin:onEnter:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (BOOL)component2 __attribute__((swift_name("component2()")));
- (void (^)(NSString *, NSString *))component3 __attribute__((swift_name("component3()")));
- (void (^)(void))component4 __attribute__((swift_name("component4()")));
- (SharedLoginPageUIState *)doCopyGreeting:(NSString *)greeting success:(BOOL)success onLogin:(void (^)(NSString *, NSString *))onLogin onEnter:(void (^)(void))onEnter __attribute__((swift_name("doCopy(greeting:success:onLogin:onEnter:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *greeting __attribute__((swift_name("greeting")));
@property (readonly) void (^onEnter)(void) __attribute__((swift_name("onEnter")));
@property (readonly) void (^onLogin)(NSString *, NSString *) __attribute__((swift_name("onLogin")));
@property (readonly) BOOL success __attribute__((swift_name("success")));
@end;

__attribute__((swift_name("LoginApiDep")))
@protocol SharedLoginApiDep
@required
- (void)loginBody:(NSString *)body onSuccess:(void (^)(NSString *))onSuccess onErr:(void (^)(NSString *))onErr __attribute__((swift_name("login(body:onSuccess:onErr:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoginFactory")))
@interface SharedLoginFactory : SharedBase
- (instancetype)initWithApiDep:(id<SharedLoginApiDep>)apiDep navigator:(id<SharedLoginNavigator>)navigator __attribute__((swift_name("init(apiDep:navigator:)"))) __attribute__((objc_designated_initializer));
- (SharedLoginFlow *)loginFlow __attribute__((swift_name("loginFlow()")));
@end;

@interface SharedBookingState (Extensions)
- (SharedBookingState *)completeCurrent __attribute__((swift_name("completeCurrent()")));
- (SharedStep *)currentStep __attribute__((swift_name("currentStep()")));
- (BOOL)isIdle __attribute__((swift_name("isIdle()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface SharedKotlinArray<T> : SharedBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(SharedInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<SharedKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol SharedKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<SharedKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<SharedKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol SharedKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<SharedKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<SharedKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol SharedKotlinx_serialization_coreKSerializer <SharedKotlinx_serialization_coreSerializationStrategy, SharedKotlinx_serialization_coreDeserializationStrategy>
@required
@end;

__attribute__((swift_name("KotlinIterator")))
@protocol SharedKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol SharedKotlinx_serialization_coreEncoder
@required
- (id<SharedKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<SharedKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<SharedKotlinx_serialization_coreEncoder>)encodeInlineInlineDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)inlineDescriptor __attribute__((swift_name("encodeInline(inlineDescriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));
- (void)encodeNull __attribute__((swift_name("encodeNull()")));
- (void)encodeNullableSerializableValueSerializer:(id<SharedKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<SharedKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) SharedKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol SharedKotlinx_serialization_coreSerialDescriptor
@required
- (NSArray<id<SharedKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));
- (id<SharedKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));
@property (readonly) NSArray<id<SharedKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));
@property (readonly) SharedKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol SharedKotlinx_serialization_coreDecoder
@required
- (id<SharedKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<SharedKotlinx_serialization_coreDecoder>)decodeInlineInlineDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)inlineDescriptor __attribute__((swift_name("decodeInline(inlineDescriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));
- (SharedKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<SharedKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<SharedKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) SharedKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol SharedKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<SharedKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));
- (void)encodeNullableSerializableElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<SharedKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<SharedKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) SharedKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface SharedKotlinx_serialization_coreSerializersModule : SharedBase
- (void)dumpToCollector:(id<SharedKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));
- (id<SharedKotlinx_serialization_coreKSerializer> _Nullable)getContextualKclass:(id<SharedKotlinKClass>)kclass __attribute__((swift_name("getContextual(kclass:)")));
- (id<SharedKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<SharedKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));
- (id<SharedKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<SharedKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end;

__attribute__((swift_name("KotlinAnnotation")))
@protocol SharedKotlinAnnotation
@required
@end;

__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface SharedKotlinx_serialization_coreSerialKind : SharedBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end;

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol SharedKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<SharedKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<SharedKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<SharedKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<SharedKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) SharedKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface SharedKotlinNothing : SharedBase
@end;

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol SharedKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<SharedKotlinKClass>)kClass serializer:(id<SharedKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<SharedKotlinKClass>)baseClass actualClass:(id<SharedKotlinKClass>)actualClass actualSerializer:(id<SharedKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<SharedKotlinKClass>)baseClass defaultSerializerProvider:(id<SharedKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultSerializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultSerializerProvider:)")));
@end;

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol SharedKotlinKDeclarationContainer
@required
@end;

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol SharedKotlinKAnnotatedElement
@required
@end;

__attribute__((swift_name("KotlinKClassifier")))
@protocol SharedKotlinKClassifier
@required
@end;

__attribute__((swift_name("KotlinKClass")))
@protocol SharedKotlinKClass <SharedKotlinKDeclarationContainer, SharedKotlinKAnnotatedElement, SharedKotlinKClassifier>
@required
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end;

#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
