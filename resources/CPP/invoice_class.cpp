#include <iostream>
#include <string>
using namespace std;

class Invoice
{
    private:
        string part_number;
        string part_description;
        int quantity;
        int price_per_item;
    public:
        Invoice(string pn, string pd, int q, int ppi)
        {
            part_number = pn;
            part_description = pd;
            quantity = (q > 0) ? q : 0;
            price_per_item = (ppi > 0) ? ppi : 0;
        }
        string getPartNumber()
        {
            return part_number;
        }
        string getPartDescription()
        {
            return part_description;
        }
        int getQuantity()
        {
            return quantity;
        }
        int getPricePerItem()
        {
            return price_per_item;
        }
        int getInvoiceAmount()
        {
            int invoice_amount = quantity * price_per_item;
            return (invoice_amount > 0) ? invoice_amount : 0;
        }
        void setPartNumber(string new_number)
        {
            part_number = new_number;
        }
        void setPartDescription(string new_description)
        {
            part_description = new_description;
        }
        void setQuantity(int new_quantity)
        {
            if (new_quantity < 0)
            {
                cout << "quantity cannot be negative. quantity set to 0.";
            }
            quantity = (new_quantity > 0) ? new_quantity : 0;
        }
        void setPricePerItem(int new_price)
        {
            if (new_price > 0)
            {
                price_per_item = new_price;
            }
        }
};


//StudybarCommentBegin
int main()
{
    // create an Invoice object
    Invoice invoice( "12345", "Hammer", 100, 5 );

    // display the invoice data members and calculate the amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;

    // modify the invoice data members
    invoice.setPartNumber( "123456" );
    invoice.setPartDescription( "Saw" );
    invoice.setQuantity( -5 ); // negative quantity, so quantity set to 0
    invoice.setPricePerItem( 10 );
    cout << "\nInvoice data members modified.\n";

    // display the modified invoice data members and calculate new amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
