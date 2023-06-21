#include "QueryBuilder.h"


SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
	query_ = "SELECT * ";
	from_ = "";
	where_ = "";
}
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
	if (query_.find("SELECT * ") != std::string::npos) {
		query_ = "SELECT " + column + " ";
	}
	else {
		query_ += ", " + column + " ";
	}
	return *this;
}
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
	from_ = " FROM " + table + " ";
	return *this;
}
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) {
	if (where_.empty()) {
		where_ = "WHERE " + column + "=" + value;
	}
	else {
		where_ += "AND " + column + "=" + value;
	}
	return *this;
}
std::string SqlSelectQueryBuilder::BuildQuery() const {
	return query_ + from_ + where_ + ";";
}