// BasicDisplayVisitor.h: File contains concrete class for displaying file contents
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
class BasicDisplayVisitor:public AbstractFileVisitor {
	public:
		void visit_TextFile(TextFile* ptr);
		void visit_ImageFile(ImageFile* ptr);
};