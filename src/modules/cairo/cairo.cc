#include <nan.h>
#include <node.h>
#include <girepository.h>
#include <glib.h>
#include <glib-object.h>

#include "../../debug.h"
#include "../../gi.h"
#include "../../gobject.h"
#include "../../value.h"
#include "context.h"
#include "font-options.h"
#include "font-extents.h"
#include "text-extents.h"
#include "matrix.h"
#include "path.h"
#include "pattern.h"
#include "rectangle.h"
#include "rectangle-int.h"
#include "region.h"
#include "surface.h"

using v8::Function;
using v8::FunctionTemplate;
using v8::Local;
using v8::MaybeLocal;
using v8::Object;

namespace GNodeJS {

namespace Cairo {

MaybeLocal<FunctionTemplate> GetTemplate(GIBaseInfo *info) {
    auto ns = g_base_info_get_namespace (info);

    if (strcmp(ns, "cairo") != 0)
        return MaybeLocal<FunctionTemplate> ();

    auto name = g_base_info_get_name (info);

    if (strcmp(name, "Context") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::Context::GetTemplate ());

    if (strcmp(name, "Matrix") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::Matrix::GetTemplate());

    if (strcmp(name, "Pattern") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::Pattern::GetTemplate());

    if (strcmp(name, "Region") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::Region::GetTemplate());

    if (strcmp(name, "FontOptions") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::FontOptions::GetTemplate());

    if (strcmp(name, "Surface") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::Surface::GetTemplate());

    if (strcmp(name, "ImageSurface") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::ImageSurface::GetTemplate());

    if (strcmp(name, "RecordingSurface") == 0)
        return MaybeLocal<FunctionTemplate> (Cairo::RecordingSurface::GetTemplate());

    return MaybeLocal<FunctionTemplate> ();
}


NAN_METHOD(Init) {
    Local<Object> cairoModule = info[0].As<Object>();

    TextExtents::Initialize(cairoModule);
    FontExtents::Initialize(cairoModule);
    Matrix::Initialize(cairoModule);
    Path::Initialize(cairoModule);
    Pattern::Initialize(cairoModule);
    Rectangle::Initialize(cairoModule);
    RectangleInt::Initialize(cairoModule);
    Region::Initialize(cairoModule);
    Surface::Initialize(cairoModule);
}

Local<Object> GetModule() {
    auto exports = Nan::New<Object>();

    Nan::Export(exports, "init", Init);

    return exports;
}


}; // System

}; // GnodeJS