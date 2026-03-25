#include <string>
#include <vector>

struct Store
{
	// -sub-types--------------------------------------------------
	struct Item
	{
		std::string name;
		std::string UPC;
		unsigned qty;
		unsigned price_USD_cents;

		Item(const std::string& n,
			 const std::string& u,
			 const unsigned& q,
			 const unsigned& p);
	};

	struct Region
	{
		std::string category;
		std::vector<Item> items;

		Region(const std::string& c);

		bool contains_item(const std::string& UPC) const;
		
		Item& get_item(const std::string& UPC);
	};

	// -top-level data---------------------------------------------
	std::vector<Region> regions;

	// -functions--------------------------------------------------
	bool has_region(const std::string& category) const;

	Region& get_region(const std::string& category);

	bool add_item(const std::string& category,
				  const std::string& name,
				  const std::string& UPC,
				  const unsigned& qty,
				  const unsigned& price_USD_cents);

	bool add_region(const std::string& category);

	void display_all() const;
};
