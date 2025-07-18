// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include "FileTreeTable.h"
#include "FileTreeTableNode.h"

#include <Wt/WText.h>

#include <Wt/cpp17/filesystem.hpp>

using namespace Wt;

FileTreeTable::FileTreeTable(const cpp17::filesystem::path& path)
  : WTreeTable()
{
  addColumn("Size", 80);
  addColumn("Modified", 110);

  header(1)->setStyleClass("fsize");
  header(2)->setStyleClass("date");

  auto tableNode
      = std::make_unique<FileTreeTableNode>(path);
  setTreeRoot(std::move(tableNode), "File");

  //treeRoot()->setImagePack("icons/");
  treeRoot()->expand();
}
