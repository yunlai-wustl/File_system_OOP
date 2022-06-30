// AbstractFileVisitor.h: File contains abstract class for visitor with pure virtual functions for visiting currently only text or image files and nothing else
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
// declaration of the file visitor interface here
#include "TextFile.h"
#include "ImageFile.h"
class AbstractFileVisitor {
	public:
		virtual void visit_TextFile(TextFile* ptr) = 0;
		virtual void visit_ImageFile(ImageFile* ptr) = 0;
};