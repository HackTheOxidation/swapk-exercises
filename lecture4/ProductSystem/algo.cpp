/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

#include <fstream>
#include <iostream>
#include <iterator>

#include <algorithm>
#include <numeric>
#include <functional>
#include <ostream>
#include <vector>
#include <string>


#define PRODUCT_DB_FILE		"product.db"

class Product
{
public:
  Product(const std::string& name, float price, unsigned int sold = 0)
    : name_(name), price_(price), sold_(sold)
  {}
  Product()
    : name_(""), price_(0), sold_(0)
  {}
  
  const std::string& name() const
  {
    return name_;
  }
  
  float price() const
  {
    return price_;
  }

  void setPrice(float newPrice)
  {
    price_ = newPrice;
  }
  
  unsigned int sold() const
  {
    return sold_;
  }
  
  friend std::istream& operator>> ( std::istream& i, Product& p );
  friend std::ostream& operator<< ( std::ostream& o, const Product& p );
  
private:
  std::string   name_;
  float         price_;
  int           sold_;
};
typedef std::vector<Product>  ProductList;


std::ostream& operator<< ( std::ostream& o, const Product& p )
{ 
  return o << p.name_ << " " << p.price_ << " " << p.sold_; 
}

std::istream& operator>> ( std::istream& i, Product& p )
{
    return i >> p.name_ >> p.price_ >> p.sold_;
}



/**
 * Read products from file
 */
void productDBRead(ProductList& pl, const std::string& fileName)
{
  pl.clear();
  std::ifstream pFile( fileName.c_str() );
  typedef std::istream_iterator<Product> iter;
  std::copy(iter(pFile), iter(), std::back_inserter(pl));
}


/**
 * Printout all products
 */
void printAll(const ProductList& pl)
{
  std::cout << "##################################################" << std::endl;
  std::cout << "Printing out all products..." << std::endl;
  std::cout << "----------------------------" << std::endl;

  std::ostream_iterator<Product> iter(std::cout, "\n");
  std::copy(pl.begin(), pl.end(), iter);

  std::cout << "##################################################" << std::endl;
}



/**
   Add item
*/
void addItem(ProductList& pl)
{
  std::cout << "##################################################" << std::endl;
  std::cout << "Enter product details (NAME PRICE #SOLD): ";
  Product p;
  std::cin >> p;
  pl.push_back(p);

  std::cout << "----------------------------" << std::endl;
  std::cout << "##################################################" << std::endl;
}


/**
   Write data to db file
*/
void productDBWrite(const ProductList& pl, const std::string& fileName)
{
  std::cout << "##################################################" << std::endl;
  std::cout << "Writing all products to database..." << std::endl;
  std::cout << "----------------------------" << std::endl;

  std::ofstream pFile( fileName.c_str() );
  std::ostream_iterator<Product> iter(pFile, "\n");
  std::copy(pl.begin(), pl.end(), iter);

  std::cout << "##################################################" << std::endl;
}


/**
 * Print poorly selling products
 */
void printPoorlySellingProducts(const ProductList& pl)
{
  std::cout << "##################################################" << std::endl;
  std::cout << "Printing out poorly selling products..." << std::endl;
  std::cout << "----------------------------" << std::endl;

  std::ostream_iterator<Product> iter(std::cout, "\n");
  std::remove_copy_if(pl.begin(), pl.end(), iter, [](Product p) {
    return p.sold() >= 10;
  });

  std::cout << "##################################################" << std::endl;
}


/**
 * Set a discount on all products - Using for_each()
 */
void addDiscountUsingForEach(ProductList& pl)
{
  std::cout << "##################################################" << std::endl;
  std::cout << "Applying 10% discount with std::for_each()..." << std::endl;
  std::cout << "----------------------------" << std::endl;
  const float discount_factor = 0.9;

  std::for_each(pl.begin(), pl.end(), [discount_factor](Product p) {
    p.setPrice(p.price() * discount_factor);
    std::cout << p << std::endl;
  });

  std::cout << "##################################################" << std::endl;
}


/**
 * Set a discount on all products - Using transform()
 */
void addDiscountUsingTransform(ProductList& pl)
{
}


/**
 * Calculate the total amount of sold products
 */
void calcTotalSoldProducts(ProductList& pl)
{
  std::cout << "##################################################" << std::endl;
  std::cout << "Calculating total number of products sold..." << std::endl;

  std::cout << "----------------------------" << std::endl;
  int total_sold = std::accumulate(pl.begin(), pl.end(), 0, [](int acc, Product p) {
    return acc + p.sold();
  });

  std::cout << "Total sold: " << total_sold << std::endl;

  std::cout << "##################################################" << std::endl;
}


/**
 * Setting discount using bind2nd - OPTIONAL
 */


int main()
{
  bool        running = true;
  ProductList pl;
  
  while(running)
  {
    char choice;
    
    std::cout << "********************" << std::endl;
    std::cout << "Help menu: " << std::endl;
    std::cout << "'1' Read product database" << std::endl;
    std::cout << "'2' Print all items" << std::endl;
    std::cout << "'3' Add item" << std::endl;
    std::cout << "'4' Write product database" << std::endl;
    std::cout << "'5' Print poorly selling products" << std::endl;
    std::cout << "'6' Set a discount on all products (using for_each() )" << std::endl;
    std::cout << "'7' Set a discount on all products (using transform() )" << std::endl;
    std::cout << "'8' Calculate the total amount of sold products" << std::endl;
    
    
    std::cout << "'q' Quit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    
    switch(choice)
    {
      case '1':
        productDBRead(pl, PRODUCT_DB_FILE);
        break;

      case '2':
        printAll(pl);
        break;

      case '3':
        addItem(pl);
        break;

      case '4':
        productDBWrite(pl, PRODUCT_DB_FILE);
        break;

      case '5':
        printPoorlySellingProducts(pl);
        break;
        
      case '6':
        addDiscountUsingForEach(pl);
        break;

      case '7':
        addDiscountUsingTransform(pl);
        break;

      case '8':
        calcTotalSoldProducts(pl);
        break;
        
      case 'q':
      case 'Q':
        running = false;
    }
    
    
  }
}
