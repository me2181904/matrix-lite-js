#include <nan.h>
#include "everloop.h"
#include "../matrix.h"


// Object Return CC TEST
NAN_METHOD(anObject) {
    // Create object
    v8::Local<v8::Object> obj = Nan::New<v8::Object>();

    // Object parameters //

    Nan::Set(obj, Nan::New("ledCountFAKE").ToLocalChecked(), Nan::New(20000));
    // # of MATRIX Leds
    int ledCount = bus.MatrixLeds();
    Nan::Set( obj, Nan::New("ledCount").ToLocalChecked(), Nan::New(ledCount) );
    // String
    //Nan::Set(obj, Nan::New("key").ToLocalChecked(), Nan::New("value").ToLocalChecked());
    
    // Return object
    info.GetReturnValue().Set(obj);
}


// EXPORTING OBJECT CONSTRUCTOR //
// Nan::Persistent<v8::FunctionTemplate> Vector::constructor;

// NAN_MODULE_INIT(Vector::Init) {
//   v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(Vector::New);
//   constructor.Reset(ctor);
//   ctor->InstanceTemplate()->SetInternalFieldCount(1);
//   ctor->SetClassName(Nan::New("Vector").ToLocalChecked());

//   Nan::SetPrototypeMethod(ctor, "add", Add);

//   target->Set(Nan::New("Vector").ToLocalChecked(), ctor->GetFunction());
// }

// NAN_METHOD(Vector::New) {
//   // throw an error if constructor is called without new keyword
//   if(!info.IsConstructCall()) {
//     return Nan::ThrowError(Nan::New("Vector::New - called without new keyword").ToLocalChecked());
//   }

//   // create a new instance and wrap our javascript instance
//   Vector* vec = new Vector();
//   vec->Wrap(info.Holder());

//   // return the wrapped javascript instance
//   info.GetReturnValue().Set(info.Holder());
// }

// NAN_METHOD(Vector::Add) {
//   // Check if argument is vector
//   auto message = Nan::New("HELLO WORLD! ):^D").ToLocalChecked();
//   info.GetReturnValue().Set(message);
// }


// BASIC WORKING EVERLOOP //
// #include <nan.h>
// #include <string>
// #include <cmath>
// #include <unistd.h>// System calls
// #include <iostream>// Input/output streams and functions
// #include "matrix_hal/everloop.h"
// #include "matrix_hal/everloop_image.h"
// #include "matrix_hal/matrixio_bus.h"

// // using namespace Nan;
// using namespace std;

// NAN_METHOD(Hello2) {
//     // Rainbow();
//     // Create an instance of V8's String type
//     //auto message = Nan::New("Hello from C++! ").ToLocalChecked();
//     auto message = Nan::New("HELLO WORLD 2! ):^D").ToLocalChecked();
//     // 'info' is a macro's "implicit" parameter - it's a bridge object between C++ and JavaScript runtimes
//     // You would use info to both extract the parameters passed to a function as well as set the return value.
//     info.GetReturnValue().Set(message);
// }

// // // EXPORTED FUNCTION //
// // NAN_METHOD(Led){

// //   //REMOVE
// //   Nan::NAN_GETTER_RETURN_TYPE
// //   auto message = Nan::New("Hello from C++! ").ToLocalChecked();
// //   info.GetReturnValue().Set(message);
// //   //REMOVE

// //   //led colors
// //   int red;
// //   int green;
// //   int blue;
// //   int white;

// //   // If param 1 is object
// //   if (!info[0]->IsObject()){
// //     // Throw error
// //     Nan::ThrowTypeError("argument must be an Object!");return;
// //   }

// //   v8::Local<v8::Object> jsonObj = info[0]->ToObject();
// //   v8::Local<v8::String> redProp = Nan::New("red").ToLocalChecked();
// //   v8::Local<v8::String> greenProp = Nan::New("green").ToLocalChecked();
// //   v8::Local<v8::String> blueProp = Nan::New("blue").ToLocalChecked();
// //   v8::Local<v8::String> whiteProp = Nan::New("white").ToLocalChecked();

// //   red = Nan::Get(jsonObj, redProp).ToLocalChecked()->NumberValue();
// //   green = Nan::Get(jsonObj, greenProp).ToLocalChecked()->NumberValue();
// //   blue = Nan::Get(jsonObj, blueProp).ToLocalChecked()->NumberValue();
// //   white = Nan::Get(jsonObj, whiteProp).ToLocalChecked()->NumberValue();

// //   /// 11111
// //   // Create new object
// //    v8::Local<v8::Object> obj = info[0]->ToObject();
// //    v8::Local<v8::String> red = Nan::New<String>("red").ToLocalChecked();
// //    v8::Local<v8::String> green = Nan::New<String>("green").ToLocalChecked();
// //    v8::Local<v8::String> blue = Nan::New<String>("blue").ToLocalChecked();
// //    v8::Local<v8::String> white = Nan::New<String>("white").ToLocalChecked();

// //   red = Nan::Get(obj, red).ToLocalChecked()->NumberValue();
// //   green = Nan::Get(obj, green).ToLocalChecked()->NumberValue();
// //   blue = Nan::Get(obj, blue).ToLocalChecked()->NumberValue();
// //   white = Nan::Get(obj, white).ToLocalChecked()->NumberValue();

// //   ///////////////////////
// //   // MATRIX LED STUFF //
// //   // Create MatrixIOBus object for hardware communication
// //   matrix_hal::MatrixIOBus bus;
// //   // Initialize bus and exit program if error occurs
// //   if (!bus.Init()) {
// //     Nan::ThrowTypeError("Error Initializing Bus");
// //     return;
// //   }

// //   // Holds the number of LEDs on MATRIX device
// //   int ledCount = bus.MatrixLeds();
// //   // Create EverloopImage object, with size of ledCount
// //   matrix_hal::EverloopImage everloop_image(ledCount);
// //   // Create Everloop object
// //   matrix_hal::Everloop everloop;
// //   // Set everloop to use MatrixIOBus bus
// //   everloop.Setup(&bus);

// //   // For each led in everloop_image.leds, set led value
// //   for (matrix_hal::LedValue &led : everloop_image.leds) {
// //     led.red = red;
// //     led.green = green;
// //     led.blue = blue;
// //     led.white = white;
// //   }

// //   // Updates the Everloop on the MATRIX device
// //   everloop.Write(&everloop_image);

// //   // MATRIX LED STUFF //
// //  //////////////////////
// // };