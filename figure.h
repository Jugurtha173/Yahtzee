#pragma once

#include <string>
#include <iostream>
#include "lancer.h"

namespace Yahtzee {

	class figure
	{
		std::string name;
		unsigned int value;
		unsigned int currentValue = 0;

		int userValue = -1;
		


		bool used = false;

	public:
		figure(const std::string& name, unsigned int value) : name(name), value(value) {};
		~figure() {};

		bool isUsed() { return used; };
		virtual unsigned int eval(lancer* roll);

		friend std::ostream& operator<<(std::ostream& out, const figure& figure) {
			return out << (figure.userValue == -1 ? "_" : std::to_string(figure.userValue)) ;
		};
		friend class partie;
		friend class joueur;
	};

}


