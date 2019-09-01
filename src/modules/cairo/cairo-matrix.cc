/* autogenerated by generator-matrix.js */

#include "../../debug.h"
#include "../../gi.h"
#include "../../util.h"
#include "cairo-matrix.h"
#include "cairo-rectangle.h"
#include "cairo-rectangle-int.h"

using namespace v8;


namespace GNodeJS {

namespace Cairo {



Nan::Persistent<FunctionTemplate> Matrix::constructorTemplate;
Nan::Persistent<Function>         Matrix::constructor;



/*
 * Initialize matrix.
 */

Matrix::Matrix(cairo_matrix_t* data) : ObjectWrap() {
  _data = data;
}

/*
 * Destroy matrix..
 */

Matrix::~Matrix() {
  if (_data != NULL) {
    delete _data;
  }
}


/*
 * Template methods
 */


Local<FunctionTemplate> Matrix::GetTemplate() {
  if (constructorTemplate.IsEmpty())
    Matrix::SetupTemplate();
  return Nan::New<FunctionTemplate> (constructorTemplate);
}

Local<Function> Matrix::GetConstructor() {
  if (constructor.IsEmpty())
    Matrix::SetupTemplate();
  return Nan::New<Function> (constructor);
}

void Matrix::SetupTemplate() {

  // Constructor
  auto tpl = Nan::New<FunctionTemplate>(Matrix::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("CairoMatrix").ToLocalChecked());

  SET_PROTOTYPE_METHOD(tpl, translate);
  SET_PROTOTYPE_METHOD(tpl, scale);
  SET_PROTOTYPE_METHOD(tpl, rotate);
  SET_PROTOTYPE_METHOD(tpl, invert);
  SET_PROTOTYPE_METHOD(tpl, transformDistance);
  SET_PROTOTYPE_METHOD(tpl, transformPoint);

  auto ctor = Nan::GetFunction (tpl).ToLocalChecked();

  SET_METHOD(ctor, initIdentity);
  SET_METHOD(ctor, initTranslate);
  SET_METHOD(ctor, initScale);
  SET_METHOD(ctor, initRotate);
  SET_METHOD(ctor, multiply);

  constructorTemplate.Reset(tpl);
  constructor.Reset(ctor);
}



/*
 * Initialize method
 */


void Matrix::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::Set (target, Nan::New ("Matrix").ToLocalChecked(), Matrix::GetConstructor());
}



/*
 * Instance constructors
 */



NAN_METHOD(Matrix::New) {
  if (!info.IsConstructCall()) {
    return Nan::ThrowTypeError("Class constructors cannot be invoked without 'new'");
  }

  cairo_matrix_t* data = NULL;

  if (info[0]->IsExternal()) {
    data = (cairo_matrix_t*) External::Cast (*info[0])->Value ();
  }
  else if (info.Length() == 6) {
    auto xx = Nan::To<double>(info[0].As<Number>()).ToChecked();
    auto yx = Nan::To<double>(info[1].As<Number>()).ToChecked();
    auto xy = Nan::To<double>(info[2].As<Number>()).ToChecked();
    auto yy = Nan::To<double>(info[3].As<Number>()).ToChecked();
    auto x0 = Nan::To<double>(info[4].As<Number>()).ToChecked();
    auto y0 = Nan::To<double>(info[5].As<Number>()).ToChecked();

    data = new cairo_matrix_t();
    cairo_matrix_init (data, xx, yx, xy, yy, x0, y0);
  }
  else if (info.Length() == 0) {
    data = new cairo_matrix_t();
  }
  else {
    return Nan::ThrowError("Cannot instantiate Matrix: requires 6 arguments");
  }

  Matrix* matrix = new Matrix(data);
  matrix->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}



/*
 * Methods
 */


NAN_METHOD(Matrix::initIdentity) {
  // out-arguments
  auto matrix = Nan::NewInstance(
            Nan::New<Function>(Matrix::constructor),
            0,
            NULL).ToLocalChecked();

  // function call
  cairo_matrix_init_identity (Nan::ObjectWrap::Unwrap<Matrix>(matrix)->_data);

  // return
  Local<Value> returnValue = matrix;
  info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Matrix::initTranslate) {
  // in-arguments
  auto tx = Nan::To<double>(info[0].As<Number>()).ToChecked();
  auto ty = Nan::To<double>(info[1].As<Number>()).ToChecked();

  // out-arguments
  auto matrix = Nan::NewInstance(
            Nan::New<Function>(Matrix::constructor),
            0,
            NULL).ToLocalChecked();

  // function call
  cairo_matrix_init_translate (Nan::ObjectWrap::Unwrap<Matrix>(matrix)->_data, tx, ty);

  // return
  Local<Value> returnValue = matrix;
  info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Matrix::initScale) {
  // in-arguments
  auto sx = Nan::To<double>(info[0].As<Number>()).ToChecked();
  auto sy = Nan::To<double>(info[1].As<Number>()).ToChecked();

  // out-arguments
  auto matrix = Nan::NewInstance(
            Nan::New<Function>(Matrix::constructor),
            0,
            NULL).ToLocalChecked();

  // function call
  cairo_matrix_init_scale (Nan::ObjectWrap::Unwrap<Matrix>(matrix)->_data, sx, sy);

  // return
  Local<Value> returnValue = matrix;
  info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Matrix::initRotate) {
  // in-arguments
  auto radians = Nan::To<double>(info[0].As<Number>()).ToChecked();

  // out-arguments
  auto matrix = Nan::NewInstance(
            Nan::New<Function>(Matrix::constructor),
            0,
            NULL).ToLocalChecked();

  // function call
  cairo_matrix_init_rotate (Nan::ObjectWrap::Unwrap<Matrix>(matrix)->_data, radians);

  // return
  Local<Value> returnValue = matrix;
  info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Matrix::translate) {
  auto self = info.This();
  auto matrix = Nan::ObjectWrap::Unwrap<Matrix>(self)->_data;

  // in-arguments
  auto tx = Nan::To<double>(info[0].As<Number>()).ToChecked();
  auto ty = Nan::To<double>(info[1].As<Number>()).ToChecked();

  // function call
  cairo_matrix_translate (matrix, tx, ty);
}


NAN_METHOD(Matrix::scale) {
  auto self = info.This();
  auto matrix = Nan::ObjectWrap::Unwrap<Matrix>(self)->_data;

  // in-arguments
  auto sx = Nan::To<double>(info[0].As<Number>()).ToChecked();
  auto sy = Nan::To<double>(info[1].As<Number>()).ToChecked();

  // function call
  cairo_matrix_scale (matrix, sx, sy);
}


NAN_METHOD(Matrix::rotate) {
  auto self = info.This();
  auto matrix = Nan::ObjectWrap::Unwrap<Matrix>(self)->_data;

  // in-arguments
  auto radians = Nan::To<double>(info[0].As<Number>()).ToChecked();

  // function call
  cairo_matrix_rotate (matrix, radians);
}


NAN_METHOD(Matrix::invert) {
  auto self = info.This();
  auto matrix = Nan::ObjectWrap::Unwrap<Matrix>(self)->_data;

  // function call
  cairo_status_t result = cairo_matrix_invert (matrix);

  // return
  Local<Value> returnValue = Nan::New (result);
  info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Matrix::multiply) {
  // in-arguments
  auto a = Nan::ObjectWrap::Unwrap<Matrix>(info[0].As<Object>())->_data;
  auto b = Nan::ObjectWrap::Unwrap<Matrix>(info[1].As<Object>())->_data;

  // out-arguments
  auto result = Nan::NewInstance(
            Nan::New<Function>(Matrix::constructor),
            0,
            NULL).ToLocalChecked();

  // function call
  cairo_matrix_multiply (Nan::ObjectWrap::Unwrap<Matrix>(result)->_data, a, b);

  // return
  Local<Value> returnValue = result;
  info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Matrix::transformDistance) {
  auto self = info.This();
  auto matrix = Nan::ObjectWrap::Unwrap<Matrix>(self)->_data;

  // in-out-arguments
  auto dx = Nan::To<double>(info[0].As<Number>()).ToChecked();
  auto dy = Nan::To<double>(info[1].As<Number>()).ToChecked();

  // function call
  cairo_matrix_transform_distance (matrix, &dx, &dy);

  // return
  Local<Object> returnValue = Nan::New<Object> ();
  Nan::Set (returnValue, UTF8 ("dx"), Nan::New (dx));
  Nan::Set (returnValue, UTF8 ("dy"), Nan::New (dy));
  info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Matrix::transformPoint) {
  auto self = info.This();
  auto matrix = Nan::ObjectWrap::Unwrap<Matrix>(self)->_data;

  // in-out-arguments
  auto x = Nan::To<double>(info[0].As<Number>()).ToChecked();
  auto y = Nan::To<double>(info[1].As<Number>()).ToChecked();

  // function call
  cairo_matrix_transform_point (matrix, &x, &y);

  // return
  Local<Object> returnValue = Nan::New<Object> ();
  Nan::Set (returnValue, UTF8 ("x"), Nan::New (x));
  Nan::Set (returnValue, UTF8 ("y"), Nan::New (y));
  info.GetReturnValue().Set(returnValue);
}




}; // Cairo

}; // GNodeJS