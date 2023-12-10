#include <stdio.h>
#include <string.h>

// Define the structure HoaDon
struct Invoice
{
    char invoiceCode[20];
    char customerName[50];
    char productName[50];
    float price;
    int quantity;
};

// Function to input invoice information
void inputInvoice(struct Invoice *invoice)
{
    printf("Enter invoice code: ");
    scanf("%s", invoice->invoiceCode);

    printf("Enter customer name: ");
    scanf("%s", invoice->customerName);

    printf("Enter product name: ");
    scanf("%s", invoice->productName);

    printf("Enter price: ");
    scanf("%f", &invoice->price);

    printf("Enter quantity: ");
    scanf("%d", &invoice->quantity);
}

// Function to calculate the total amount of the invoice
float calculateTotalAmount(struct Invoice invoice)
{
    return invoice.price * invoice.quantity;
}

// Function to calculate the discount
float calculateDiscount(struct Invoice invoice)
{
    if (invoice.quantity > 50 || strcmp(invoice.productName, "mitsumi mouse") == 0)
    {
        return 0.1; // 10% discount
    }
    else
    {
        return 0.05; // 5% discount
    }
}

// Function to display invoice information
void displayInvoice(struct Invoice invoice)
{
    float totalAmount = calculateTotalAmount(invoice);
    float discount = totalAmount * calculateDiscount(invoice);

    printf("\nInvoice Information:\n");
    printf("Invoice Code: %s\n", invoice.invoiceCode);
    printf("Customer Name: %s\n", invoice.customerName);
    printf("Product Name: %s\n", invoice.productName);
    printf("Total Amount: %.2f\n", totalAmount);
    printf("Discount: %.2f\n", discount);
}

int main()
{
    struct Invoice invoice;

    // Input invoice information
    inputInvoice(&invoice);

    // Display invoice information
    displayInvoice(invoice);

    return 0;
}