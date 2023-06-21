#include <iostream>
#include "SqlQueryBuilder.h"


int main() {

	setlocale(LC_ALL, "rus");

	SqlSelectQueryBuilder query_builder;

	std::string query = query_builder.BuildQuery();
	std::cout << query << std::endl;

	return 0;
}