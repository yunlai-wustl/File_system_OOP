// DisplayCommand.h: File contains concrete class for displaying the file name for the passed pointer
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractFileVisitor.h"
class GrepDisplayVisitor :public AbstractFileVisitor {
public:
	void visit_TextFile(TextFile* ptr);
	void visit_ImageFile(ImageFile* ptr);
};