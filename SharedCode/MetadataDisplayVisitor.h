// MetaDataDisplayVisitor.h: File contains concrete class for displaying a file with its metadata
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include <string>

#include "AbstractFileVisitor.h"
// declaration of MetadataDisplayVisitor here
class MetadataDisplayVisitor :public AbstractFileVisitor {
	public:
		void visit_TextFile(TextFile* ptr);
		void visit_ImageFile(ImageFile* ptr);
};