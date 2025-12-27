#include "Item.h"
#include <utility>

Item::Item(std::string name) : m_name(std::move(name)) {}

const std::string& Item::GetName() const { return m_name; }
