#include "exporthtml.h"

ExportHTML::ExportHTML() {

}

ExportHTML::~ExportHTML() {

}

void ExportHTML::export_assignment(Assignment* a) {
    Assignment* b = &*a;
    b = nullptr;
}
