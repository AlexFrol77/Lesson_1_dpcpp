#include <iostream>
#include "QueryBuilder.h"



int main() {

	setlocale(LC_ALL, "rus");

	SqlSelectQueryBuilder query_builder;
	
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");

	std::string query = query_builder.BuildQuery();
	std::cout << query << std::endl;
	return 0;
}