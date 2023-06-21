#pragma once
#include <string>
#include <vector>

class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder();

	SqlSelectQueryBuilder& AddColumn(const std::string& column);

	SqlSelectQueryBuilder& AddFrom(const std::string& table);

	SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value);

	std::string BuildQuery() const;

private:
	std::string query_;
	std::string from_;
	std::string where_;
};