#include "store.h"
#include <iostream>
#include <print>
#include <stdexcept>

Store::Item::Item(const std::string& n,
				  const std::string& u,
				  const unsigned& q,
				  const unsigned& p)
	: name(n), UPC(u), qty(q), price_USD_cents(p) {}

Store::Region::Region(const std::string& c): category(c) {}

bool Store::Region::contains_item(const std::string& UPC) const
{
	for (const Item& item: items) {
		if (item.UPC == UPC) {
			return true;
		}
	}

	return false;
}

Store::Item& Store::Region::get_item(const std::string& UPC)
{
	for (Item& item: items) {
		if (item.UPC == UPC) {
			return item;
		}
	}

	throw std::invalid_argument("product with UPC " + UPC + " DNE.");
}

bool Store::has_region(const std::string& category) const
{
	for (const Region& r: regions) {
		if (r.category == category) {
			return true;
		}
	}

	return false;
}

Store::Region& Store::get_region(const std::string& category)
{
	for (Region& r: regions) {
		if (r.category == category) {
			return r;
		}
	}

	throw std::invalid_argument(category + " is not a region in the store.");
}

bool Store::add_item(const std::string& category,
				     const std::string& name,
				     const std::string& UPC,
				     const unsigned& qty,
				     const unsigned& price_USD_cents)
{
	if (not has_region(category)) {
		std::cerr << "ERR: given category(" << category << ") DNE.\n";
		return false;
	}

	Region& region = get_region(category);

	if (region.contains_item(UPC)) { // ERR: item already exists with UPC
		std::cerr << "ERR: item with UPC (" << UPC << ") already exists in the "
				  << '"' << category << "\" region.";
		return false;
	}
	else {
		region.items.emplace_back(name, UPC, qty, price_USD_cents);
		return true;
	}
}

bool Store::add_region(const std::string& category)
{
	if (has_region(category)) {
		std::cerr << "ERR: " << category << " already found in stored regions.\n";
		return false;
	}
	else {
		regions.emplace_back(category);
		return true;
	}
}

void Store::display_all() const
{
	if (regions.empty()) {
		std::cout << "The store is empty." << std::endl;
		return;
	}

	for (const Region& region: regions) {
		std::cout << region.category << ":\n";

		for (const Item& item: region.items) {
			float price_USD = (item.price_USD_cents / 100.0f);
			
			std::println("\t- {}(x{})<UPC:{}>, ${:.2f}",
					     item.name,
						 item.qty,
						 item.UPC,
						 price_USD);
		}
	}
}
