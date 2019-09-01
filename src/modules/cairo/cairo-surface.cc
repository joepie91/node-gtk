/* autogenerated by generator-surface.js */

#include "../../debug.h"
#include "../../gi.h"
#include "../../util.h"
#include "cairo-surface.h"
#include "cairo-rectangle.h"
#include "cairo-rectangle-int.h"

using namespace v8;


namespace GNodeJS {

namespace Cairo {



Nan::Persistent<FunctionTemplate> Surface::constructorTemplate;
Nan::Persistent<Function>         Surface::constructor;


Nan::Persistent<FunctionTemplate> ImageSurface::constructorTemplate;
Nan::Persistent<Function>         ImageSurface::constructor;


Nan::Persistent<FunctionTemplate> RecordingSurface::constructorTemplate;
Nan::Persistent<Function>         RecordingSurface::constructor;



/*
 * Initialize surface.
 */

Surface::Surface(cairo_surface_t* data) : ObjectWrap() {
  _data = data;
}

/*
 * Destroy surface..
 */

Surface::~Surface() {
  if (_data != NULL) {
    cairo_surface_destroy (_data);
  }
}


/*
 * Template methods
 */


Local<FunctionTemplate> Surface::GetTemplate() {
  if (constructorTemplate.IsEmpty())
    Surface::SetupTemplate();
  return Nan::New<FunctionTemplate> (constructorTemplate);
}

Local<Function> Surface::GetConstructor() {
  if (constructor.IsEmpty())
    Surface::SetupTemplate();
  return Nan::New<Function> (constructor);
}

void Surface::SetupTemplate() {

  // Constructor
  auto tpl = Nan::New<FunctionTemplate>(Surface::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("CairoSurface").ToLocalChecked());


  SET_PROTOTYPE_METHOD(tpl, writeToPng);
  SET_PROTOTYPE_METHOD(tpl, status);
  SET_PROTOTYPE_METHOD(tpl, finish);
  SET_PROTOTYPE_METHOD(tpl, flush);
  SET_PROTOTYPE_METHOD(tpl, getDevice);
  SET_PROTOTYPE_METHOD(tpl, getContent);
  SET_PROTOTYPE_METHOD(tpl, markDirty);
  SET_PROTOTYPE_METHOD(tpl, markDirtyRectangle);
  SET_PROTOTYPE_METHOD(tpl, setDeviceOffset);
  SET_PROTOTYPE_METHOD(tpl, getDeviceOffset);
  SET_PROTOTYPE_METHOD(tpl, getDeviceScale);
  SET_PROTOTYPE_METHOD(tpl, setDeviceScale);
  SET_PROTOTYPE_METHOD(tpl, setFallbackResolution);
  SET_PROTOTYPE_METHOD(tpl, getFallbackResolution);
  SET_PROTOTYPE_METHOD(tpl, getType);
  SET_PROTOTYPE_METHOD(tpl, getReferenceCount);
  SET_PROTOTYPE_METHOD(tpl, copyPage);
  SET_PROTOTYPE_METHOD(tpl, showPage);
  SET_PROTOTYPE_METHOD(tpl, hasShowTextGlyphs);
  SET_PROTOTYPE_METHOD(tpl, supportsMimeType);
  SET_PROTOTYPE_METHOD(tpl, mapToImage);
  SET_PROTOTYPE_METHOD(tpl, unmapImage);

  auto ctor = Nan::GetFunction (tpl).ToLocalChecked();

  SET_METHOD(ctor, createSimilar);
  SET_METHOD(ctor, createSimilarImage);
  SET_METHOD(ctor, createForRectangle);

  constructorTemplate.Reset(tpl);
  constructor.Reset(ctor);


  ImageSurface::SetupTemplate(tpl);
  RecordingSurface::SetupTemplate(tpl);
}


Local<FunctionTemplate> ImageSurface::GetTemplate() {
  if (constructorTemplate.IsEmpty())
    Surface::SetupTemplate();
  return Nan::New<FunctionTemplate> (constructorTemplate);
}

Local<Function> ImageSurface::GetConstructor() {
  if (constructor.IsEmpty())
    Surface::SetupTemplate();
  return Nan::New<Function> (constructor);
}

void ImageSurface::SetupTemplate(Local<FunctionTemplate> parentTpl) {

  // Constructor
  auto tpl = Nan::New<FunctionTemplate>(ImageSurface::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("CairoImageSurface").ToLocalChecked());
  tpl->Inherit (parentTpl);

  SET_PROTOTYPE_METHOD(tpl, getData);
  SET_PROTOTYPE_METHOD(tpl, getFormat);
  SET_PROTOTYPE_METHOD(tpl, getWidth);
  SET_PROTOTYPE_METHOD(tpl, getHeight);
  SET_PROTOTYPE_METHOD(tpl, getStride);

  auto ctor = Nan::GetFunction (tpl).ToLocalChecked();

  SET_METHOD(ctor, createFromPng);

  constructorTemplate.Reset(tpl);
  constructor.Reset(ctor);

}


Local<FunctionTemplate> RecordingSurface::GetTemplate() {
  if (constructorTemplate.IsEmpty())
    Surface::SetupTemplate();
  return Nan::New<FunctionTemplate> (constructorTemplate);
}

Local<Function> RecordingSurface::GetConstructor() {
  if (constructor.IsEmpty())
    Surface::SetupTemplate();
  return Nan::New<Function> (constructor);
}

void RecordingSurface::SetupTemplate(Local<FunctionTemplate> parentTpl) {

  // Constructor
  auto tpl = Nan::New<FunctionTemplate>(RecordingSurface::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("CairoRecordingSurface").ToLocalChecked());
  tpl->Inherit (parentTpl);

  SET_PROTOTYPE_METHOD(tpl, inkExtents);
  SET_PROTOTYPE_METHOD(tpl, getExtents);

  auto ctor = Nan::GetFunction (tpl).ToLocalChecked();



  constructorTemplate.Reset(tpl);
  constructor.Reset(ctor);

}



/*
 * Initialize method
 */


void Surface::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::Set (target, Nan::New ("Surface").ToLocalChecked(), Surface::GetConstructor());
  Nan::Set (target, Nan::New ("ImageSurface").ToLocalChecked(), ImageSurface::GetConstructor());
  Nan::Set (target, Nan::New ("RecordingSurface").ToLocalChecked(), RecordingSurface::GetConstructor());
}



/*
 * Instance constructors
 */



NAN_METHOD(Surface::New) {
  if (!info.IsConstructCall()) {
    return Nan::ThrowTypeError("Class constructors cannot be invoked without 'new'");
  }

  cairo_surface_t* data = NULL;

  if (info[0]->IsExternal()) {
    data = (cairo_surface_t*) External::Cast (*info[0])->Value ();
  }
  else {
    return Nan::ThrowError("Cannot instantiate Surface: abstract type");
  }

  Surface* surface = new Surface(data);
  surface->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}



NAN_METHOD(ImageSurface::New) {
  if (!info.IsConstructCall()) {
    return Nan::ThrowTypeError("Class constructors cannot be invoked without 'new'");
  }

  cairo_surface_t* data = NULL;

  if (info[0]->IsExternal()) {
    data = (cairo_surface_t*) External::Cast (*info[0])->Value ();
  }
  else if (info.Length() == 3) {
    auto format = (cairo_format_t) Nan::To<int64_t>(info[0].As<Number>()).ToChecked();
    auto width = Nan::To<int64_t>(info[1].As<Number>()).ToChecked();
    auto height = Nan::To<int64_t>(info[2].As<Number>()).ToChecked();

    data = cairo_image_surface_create (format, width, height);
  }
  else {
    return Nan::ThrowError("Cannot instantiate ImageSurface: requires 3 arguments");
  }

  ImageSurface* surface = new ImageSurface(data);
  surface->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}



NAN_METHOD(RecordingSurface::New) {
  if (!info.IsConstructCall()) {
    return Nan::ThrowTypeError("Class constructors cannot be invoked without 'new'");
  }

  cairo_surface_t* data = NULL;

  if (info[0]->IsExternal()) {
    data = (cairo_surface_t*) External::Cast (*info[0])->Value ();
  }
  else if (info.Length() == 2) {
    auto content = (cairo_content_t) Nan::To<int64_t>(info[0].As<Number>()).ToChecked();
    auto extents = Nan::ObjectWrap::Unwrap<Rectangle>(info[1].As<Object>())->_data;

    data = cairo_recording_surface_create (content, extents);
  }
  else {
    return Nan::ThrowError("Cannot instantiate RecordingSurface: requires 2 arguments");
  }

  RecordingSurface* surface = new RecordingSurface(data);
  surface->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}



/*
 * Methods
 */


NAN_METHOD(Surface::createSimilar) {
    // in-arguments
    auto other = Nan::ObjectWrap::Unwrap<Surface>(info[0].As<Object>())->_data;
    auto content = (cairo_content_t) Nan::To<int64_t>(info[1].As<Number>()).ToChecked();
    auto width = Nan::To<int64_t>(info[2].As<Number>()).ToChecked();
    auto height = Nan::To<int64_t>(info[3].As<Number>()).ToChecked();

    // function call
    cairo_surface_t * result = cairo_surface_create_similar (other, content, width, height);

    // return
    Local<Value> args[] = { Nan::New<External> (result) };
    Local<Function> constructor = Nan::New<Function> (Surface::constructor);
    Local<Value> returnValue = Nan::NewInstance(constructor, 1, args).ToLocalChecked();
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::createSimilarImage) {
    // in-arguments
    auto other = Nan::ObjectWrap::Unwrap<Surface>(info[0].As<Object>())->_data;
    auto format = (cairo_format_t) Nan::To<int64_t>(info[1].As<Number>()).ToChecked();
    auto width = Nan::To<int64_t>(info[2].As<Number>()).ToChecked();
    auto height = Nan::To<int64_t>(info[3].As<Number>()).ToChecked();

    // function call
    cairo_surface_t * result = cairo_surface_create_similar_image (other, format, width, height);

    // return
    Local<Value> args[] = { Nan::New<External> (result) };
    Local<Function> constructor = Nan::New<Function> (Surface::constructor);
    Local<Value> returnValue = Nan::NewInstance(constructor, 1, args).ToLocalChecked();
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::createForRectangle) {
    // in-arguments
    auto target = Nan::ObjectWrap::Unwrap<Surface>(info[0].As<Object>())->_data;
    auto x = Nan::To<double>(info[1].As<Number>()).ToChecked();
    auto y = Nan::To<double>(info[2].As<Number>()).ToChecked();
    auto width = Nan::To<double>(info[3].As<Number>()).ToChecked();
    auto height = Nan::To<double>(info[4].As<Number>()).ToChecked();

    // function call
    cairo_surface_t * result = cairo_surface_create_for_rectangle (target, x, y, width, height);

    // return
    Local<Value> args[] = { Nan::New<External> (result) };
    Local<Function> constructor = Nan::New<Function> (Surface::constructor);
    Local<Value> returnValue = Nan::NewInstance(constructor, 1, args).ToLocalChecked();
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::writeToPng) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto filename = *Nan::Utf8String (info[0].As<String>());

    // function call
    cairo_status_t result = cairo_surface_write_to_png (surface, filename);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::status) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_status_t result = cairo_surface_status (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::finish) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_surface_finish (surface);
}


NAN_METHOD(Surface::flush) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_surface_flush (surface);
}


NAN_METHOD(Surface::getDevice) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_device_t * result = cairo_surface_get_device (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::getContent) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_content_t result = cairo_surface_get_content (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::markDirty) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_surface_mark_dirty (surface);
}


NAN_METHOD(Surface::markDirtyRectangle) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto x = Nan::To<int64_t>(info[0].As<Number>()).ToChecked();
    auto y = Nan::To<int64_t>(info[1].As<Number>()).ToChecked();
    auto width = Nan::To<int64_t>(info[2].As<Number>()).ToChecked();
    auto height = Nan::To<int64_t>(info[3].As<Number>()).ToChecked();

    // function call
    cairo_surface_mark_dirty_rectangle (surface, x, y, width, height);
}


NAN_METHOD(Surface::setDeviceOffset) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto x_offset = Nan::To<double>(info[0].As<Number>()).ToChecked();
    auto y_offset = Nan::To<double>(info[1].As<Number>()).ToChecked();

    // function call
    cairo_surface_set_device_offset (surface, x_offset, y_offset);
}


NAN_METHOD(Surface::getDeviceOffset) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // out-arguments
    double x_offset = 0.0;
    double y_offset = 0.0;

    // function call
    cairo_surface_get_device_offset (surface, &x_offset, &y_offset);

    // return
    Local<Object> returnValue = Nan::New<Object> ();
    Nan::Set (returnValue, UTF8 ("x_offset"), Nan::New (x_offset));
    Nan::Set (returnValue, UTF8 ("y_offset"), Nan::New (y_offset));
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::getDeviceScale) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // out-arguments
    double x_scale = 0.0;
    double y_scale = 0.0;

    // function call
    cairo_surface_get_device_scale (surface, &x_scale, &y_scale);

    // return
    Local<Object> returnValue = Nan::New<Object> ();
    Nan::Set (returnValue, UTF8 ("x_scale"), Nan::New (x_scale));
    Nan::Set (returnValue, UTF8 ("y_scale"), Nan::New (y_scale));
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::setDeviceScale) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto x_scale = Nan::To<double>(info[0].As<Number>()).ToChecked();
    auto y_scale = Nan::To<double>(info[1].As<Number>()).ToChecked();

    // function call
    cairo_surface_set_device_scale (surface, x_scale, y_scale);
}


NAN_METHOD(Surface::setFallbackResolution) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto x_pixels_per_inch = Nan::To<double>(info[0].As<Number>()).ToChecked();
    auto y_pixels_per_inch = Nan::To<double>(info[1].As<Number>()).ToChecked();

    // function call
    cairo_surface_set_fallback_resolution (surface, x_pixels_per_inch, y_pixels_per_inch);
}


NAN_METHOD(Surface::getFallbackResolution) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // out-arguments
    double x_pixels_per_inch = 0.0;
    double y_pixels_per_inch = 0.0;

    // function call
    cairo_surface_get_fallback_resolution (surface, &x_pixels_per_inch, &y_pixels_per_inch);

    // return
    Local<Object> returnValue = Nan::New<Object> ();
    Nan::Set (returnValue, UTF8 ("x_pixels_per_inch"), Nan::New (x_pixels_per_inch));
    Nan::Set (returnValue, UTF8 ("y_pixels_per_inch"), Nan::New (y_pixels_per_inch));
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::getType) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_surface_type_t result = cairo_surface_get_type (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::getReferenceCount) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    int unsigned result = cairo_surface_get_reference_count (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::copyPage) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_surface_copy_page (surface);
}


NAN_METHOD(Surface::showPage) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_surface_show_page (surface);
}


NAN_METHOD(Surface::hasShowTextGlyphs) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // function call
    cairo_bool_t result = cairo_surface_has_show_text_glyphs (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::supportsMimeType) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto mime_type = *Nan::Utf8String (info[0].As<String>());

    // function call
    cairo_bool_t result = cairo_surface_supports_mime_type (surface, mime_type);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::mapToImage) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto extents = Nan::ObjectWrap::Unwrap<RectangleInt>(info[0].As<Object>())->_data;

    // function call
    cairo_surface_t * result = cairo_surface_map_to_image (surface, extents);

    // return
    Local<Value> args[] = { Nan::New<External> (result) };
    Local<Function> constructor = Nan::New<Function> (Surface::constructor);
    Local<Value> returnValue = Nan::NewInstance(constructor, 1, args).ToLocalChecked();
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(Surface::unmapImage) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<Surface>(self)->_data;

    // in-arguments
    auto image = Nan::ObjectWrap::Unwrap<Surface>(info[0].As<Object>())->_data;

    // function call
    cairo_surface_unmap_image (surface, image);
}


NAN_METHOD(ImageSurface::createFromPng) {
    // in-arguments
    auto filename = *Nan::Utf8String (info[0].As<String>());

    // function call
    cairo_surface_t * result = cairo_image_surface_create_from_png (filename);

    // return
    Local<Value> args[] = { Nan::New<External> (result) };
    Local<Function> constructor = Nan::New<Function> (Surface::constructor);
    Local<Value> returnValue = Nan::NewInstance(constructor, 1, args).ToLocalChecked();
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(ImageSurface::getData) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<ImageSurface>(self)->_data;

    // function call
    char unsigned * result = cairo_image_surface_get_data (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(ImageSurface::getFormat) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<ImageSurface>(self)->_data;

    // function call
    cairo_format_t result = cairo_image_surface_get_format (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(ImageSurface::getWidth) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<ImageSurface>(self)->_data;

    // function call
    int result = cairo_image_surface_get_width (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(ImageSurface::getHeight) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<ImageSurface>(self)->_data;

    // function call
    int result = cairo_image_surface_get_height (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(ImageSurface::getStride) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<ImageSurface>(self)->_data;

    // function call
    int result = cairo_image_surface_get_stride (surface);

    // return
    Local<Value> returnValue = Nan::New (result);
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(RecordingSurface::inkExtents) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<RecordingSurface>(self)->_data;

    // out-arguments
    double x0 = 0.0;
    double y0 = 0.0;
    double width = 0.0;
    double height = 0.0;

    // function call
    cairo_recording_surface_ink_extents (surface, &x0, &y0, &width, &height);

    // return
    Local<Object> returnValue = Nan::New<Object> ();
    Nan::Set (returnValue, UTF8 ("x0"), Nan::New (x0));
    Nan::Set (returnValue, UTF8 ("y0"), Nan::New (y0));
    Nan::Set (returnValue, UTF8 ("width"), Nan::New (width));
    Nan::Set (returnValue, UTF8 ("height"), Nan::New (height));
    info.GetReturnValue().Set(returnValue);
}


NAN_METHOD(RecordingSurface::getExtents) {
    auto self = info.This();
    auto surface = Nan::ObjectWrap::Unwrap<RecordingSurface>(self)->_data;

    // out-arguments
    auto extents = Nan::NewInstance(
            Nan::New<Function>(Rectangle::constructor),
            0,
            NULL).ToLocalChecked();

    // function call
    cairo_bool_t result = cairo_recording_surface_get_extents (surface, Nan::ObjectWrap::Unwrap<Rectangle>(extents)->_data);

    // return
    Local<Value> returnValue = extents;
    info.GetReturnValue().Set(returnValue);
}




}; // Cairo

}; // GNodeJS