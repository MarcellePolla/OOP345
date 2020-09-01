#ifndef BOOK_H
#define BOOK_H
namespace sdds{
	class Book{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_description;
		double m_price;
		size_t m_yearPublication;
	public:
		Book();
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, Book& book);
}
#endif