#include "SqlQueryBuilder.h"


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
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
	if (!columns.empty()) {
		if (query_.find("SELECT * ") != std::string::npos) {
			query_ = "SELECT " + columns.at(0);
			for (size_t i = 1; i < columns.size(); i++) {
				query_ += ", " + columns.at(i);
			}
		}
		else {
			for (const auto& column : columns) {
				query_ += ", " + column;
			}
		}
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
		where_ += " AND " + column + "=" + value;
	}
	return *this;
}
SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
	if (!kv.empty()) {
		for (const auto& pair : kv) {
			if (where_.empty()) {
				where_ = "WHERE " + pair.first + "=" + pair.second;
			}
			else {
				where_ += " AND " + pair.first + "=" + pair.second;
			}
		}
	}
	return *this;
}
std::string SqlSelectQueryBuilder::BuildQuery() const {
	return query_ + from_ + where_ + ";";
}