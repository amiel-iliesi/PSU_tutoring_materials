#pragma once
#include "classes.h"

class CarList
{
	private:
		class CarNode : public Car
		{
			private:
				CarNode * next;

			public:
				CarNode();
				CarNode(unsigned, unsigned, unsigned,
					    unsigned, unsigned, FuelType, const char *,
						CarNode*);
				
				void set_next(CarNode*);
				CarNode * get_next();
		};

		CarNode * head;
	
	public:
		CarList();
		~CarList();

		void append(unsigned, unsigned, unsigned,
					unsigned, unsigned, Car::FuelType, const char *);

		void display() const;
};
