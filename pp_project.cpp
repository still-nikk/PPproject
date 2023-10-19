#include <iostream>
#include <string>
using namespace std;
const int max_books = 100;
const int max_movies = 100;

class product 
{
public:
    product(string name)
        : name(name) {
            int l = 150;
            int u = 500;
            price = (rand() % (u - l + 1)) + l;
        }

    virtual ~product() {}

    virtual void display() 
    {
        cout << "Name: " << name << endl;
        cout << "Price: Rs." << price << endl;
    }

    friend class inventory;

protected:
    string name;
    double price;
};

class movie : public product
{
    public:

    movie(string title, string language, int year)
        : product(title), language(language), year(year) {
            int n = 10;
            qty = rand() % n;
            int l = 1100;
            int u = 1200;
            id = (rand() % (u - l + 1)) + l;
        }

    movie() : product(""), language(""), year(0) {}

    void display()
    {
        product :: display();
        cout << "Product ID: " << id << endl;
        cout << "Language: " << language << endl;
        cout << "Year: " << year << endl;
        cout << "Quantity: " << qty <<endl;
    }

    friend class inventory;

    private:
    int id;
    int qty;
    string language;
    int year;
};

class book : public product 
{
public:

    book(string title, string author, int year)
        : product(title), author(author), year(year) {
            int n = 10;
            qty = rand() % n;
            int l = 2100;
            int u = 2200;
            id = (rand() % (u - l + 1)) + l;
        }

    book() : product(""), author(""), year(0) {}
    void display()
    {
        product::display();
        cout << "Product ID: " << id << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Quantity: " << qty <<endl;
    }

    friend class inventory;

private:
    int qty;
    int id;
    string author;
    int year;
};

class inventory 
{
public:
    inventory()
    {
        num_books = 0;
        num_movies = 0;
    }

    void add_books(string name, string author, int year) 
    {
        if (num_books < max_books) 
        {
            books[num_books++] = book(name, author, year);
            // cout << "Product added to inventory." << endl;
            for (int i = 0; i < num_books - 1; i++)
            {
                for (int j = 0; j < num_books - i - 1; j++)
                {
                    if (books[j].name > books[j + 1].name)
                    {
                        // Swap books[j] and books[j + 1]
                        book temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                }
            }
        } 
        else 
        {
            cout << "Inventory is full. Cannot add more products." << endl;
        }

    }

    void add_movies(string name, string language, int year)
    {
        if(num_movies < max_movies)
        {
            movies[num_movies++] = movie(name,language,year);
            for (int i = 0; i < num_movies - 1; i++)
            {
                for (int j = 0; j < num_movies - i - 1; j++)
                {
                    if (movies[j].name > movies[j + 1].name)
                    {
                        // Swap movies[j] and movies[j + 1]
                        movie temp = movies[j];
                        movies[j] = movies[j + 1];
                        movies[j + 1] = temp;
                    }
                }
            }
        }
        else
        {
            cout << "Inventory is full. Cannot add more products." << endl;
        }
    }

    void list_options()
    {
        cout << "Choose any of your choice: " << endl;
        cout << "S.No.:       Category:" << endl;
        cout << "1            Books"<<endl;
        cout << "2            Movies"<<endl;
        cout << "3            EXIT"<<endl;
    }

    void list_books() 
    {
        cout << "Books inventory:"<<endl;
        for(int i = 0; i < num_books; ++i) 
        {
            books[i].display();
            cout << "-------------------------"<<endl;
        }
    }

    void list_movies()
    {
        cout << "Movies inventory:"<<endl;
        for(int i = 0; i < num_movies; ++i)
        {
            movies[i].display();
            cout << "-------------------------"<<endl;
        }
    }

    void search_book() 
    {  
        int book_id;
        cout << "Enter the Product ID of the Book you want to search for: ";
        cin >> book_id;
        cout << "Searching for Product ID: " << book_id << endl;
        for (int i = 0; i < num_books; ++i) 
        {
            if (books[i].id == book_id) 
            {
                if(books[i].qty > 0 && books[i].qty < 2)
                {
                cout << " 1 copy of this book is available." << endl << "book details: "<< endl ;
                books[i].display();
                }
                else if(books[i].qty > 1)
                {
                    cout << books[i].qty << " copies of this book are available." << endl << "book details: "<< endl ;
                    books[i].display();
                }
                else
                {
                    cout << "Sorry! No more copies of this book are left."<<endl;
                }
                return;
            }
        }
        cout << "Product not found. Kindly recheck the Product ID you've entered."<<endl;
    }

    void search_movie()
    {
        int movie_id;
        cout << "Enter the Product ID of the Movie you want to search for: ";
        cin >> movie_id;
        cout << "Searching for product: " << movie_id << endl;
        for (int i = 0; i < num_movies; ++i) 
        {
            if (movies[i].id == movie_id) 
            {
                if(movies[i].qty > 0 && movies[i].qty < 2)
                {
                cout << " 1 copy of the movie is available." << endl << "Movie details: "<< endl ;
                movies[i].display();
                }
                else if(movies[i].qty > 1)
                {
                    cout << movies[i].qty << " copies of the movie are available." << endl << "Movie details: "<< endl ;
                    movies[i].display();
                }
                else
                {
                    cout << "Sorry! No more copies of this movie are left."<<endl;
                }
                return;
            }
        }
        cout << "Product not found. Kindly recheck the Product ID you entered."<<endl;
    }

private:
    book books[max_books];
    movie movies[max_movies];
    int num_books;
    int num_movies;
};

int main() 
{
    int choice;
    inventory inv;
    inv.add_books("It ends with us.", "Colleen Hoover", 2016);
    inv.add_books("It starts with us.", "Colleen Hoover", 2022);
    inv.add_books("To Kill a Mockingbird", "Harper Lee", 1960);
    inv.add_books("1984", "George Orwell", 1949);
    inv.add_books("Pride and Prejudice", "Jane Austen", 1813);
    inv.add_books("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    inv.add_books("The Catcher in the Rye", "J.D. Salinger", 1951);
    inv.add_books("Dune", "Frank Herbert", 1965);
    inv.add_books("Neuromancer", "William Gibson", 1984);
    inv.add_books("Foundation", "Isaac Asimov", 1951);
    inv.add_books("Brave New World", "Aldous Huxley", 1932);
    inv.add_books("The Hunger Games", "Suzanne Collins", 2008);
    inv.add_books("The Da Vinci Code", "Dan Brown", 2003);
    inv.add_books("Gone Girl", "Gillian Flynn", 2012);
    inv.add_books("The Girl with the Dragon Tattoo", "Stieg Larsson", 2005);
    inv.add_books("The Hound of the Baskervilles", "Arthur Conan Doyle", 1902);
    inv.add_books("The Silence of the Lambs", "Thomas Harris", 1988);
    inv.add_books("The Hobbit", "J.R.R. Tolkien", 1937);
    inv.add_books("A Song of Ice and Fire", "George R.R. Martin", 1996);
    inv.add_books("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 1997);
    inv.add_books("The Name of the Wind", "Patrick Rothfuss", 2007);
    inv.add_books("The Chronicles of Narnia", "C.S. Lewis", 1950);
    inv.add_books("The Diary of a Young Girl", "Anne Frank", 1947);
    inv.add_books("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 2014);
    inv.add_books("The Immortal Life of Henrietta Lacks", "Rebecca Skloot", 2010);
    inv.add_books("The Power of Habit", "Charles Duhigg", 2012);
    inv.add_books("Thinking, Fast and Slow", "Daniel Kahneman", 2011);
    inv.add_books("Moby-Dick", "Herman Melville", 1851);
    inv.add_books("One Hundred Years of Solitude", "Gabriel Garcia Marquez", 1967);
    inv.add_books("The Odyssey", "Homer", -800);
    inv.add_books("The Road", "Cormac McCarthy", 2006);
    inv.add_books("Wuthering Heights", "Emily Brontë", 1847);
    inv.add_books("Crime and Punishment", "Fyodor Dostoevsky", 1866);
    inv.add_books("The Sun Also Rises", "Ernest Hemingway", 1926);
    inv.add_books("The Alchemist", "Paulo Coelho", 1988);
    inv.add_books("The Picture of Dorian Gray", "Oscar Wilde", 1890);
    inv.add_books("War and Peace", "Leo Tolstoy", 1869);
    inv.add_books("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979);
    inv.add_books("The Road Less Traveled", "M. Scott Peck", 1978);
    inv.add_books("The Shining", "Stephen King", 1977);
    inv.add_books("The Lord of the Flies", "William Golding", 1954);
    inv.add_books("The Grapes of Wrath", "John Steinbeck", 1939);
    inv.add_books("The Martian", "Andy Weir", 2011);
    inv.add_books("The Old Man and the Sea", "Ernest Hemingway", 1952);
    inv.add_books("The Secret Garden", "Frances Hodgson Burnett", 1911);
    inv.add_books("The Road to Wigan Pier", "George Orwell", 1937);
    inv.add_books("The Wind in the Willows", "Kenneth Grahame", 1908);
    inv.add_books("The War of the Worlds", "H.G. Wells", 1898);
    inv.add_books("The Stand", "Stephen King", 1978);
    inv.add_books("The Metamorphosis", "Franz Kafka", 1915);
    inv.add_books("The Handmaid's Tale", "Margaret Atwood", 1985);
    inv.add_books("The Stranger", "Albert Camus", 1942);
    inv.add_books("The Little Prince", "Antoine de Saint-Exupéry", 1943);
    inv.add_books("The Fault in Our Stars", "John Green", 2012);
    inv.add_books("The Road to Character", "David Brooks", 2015);
    inv.add_books("The Kite Runner", "Khaled Hosseini", 2003);
    inv.add_books("The Silence of the Girls", "Pat Barker", 2018);
    inv.add_books("A Clockwork Orange", "Anthony Burgess", 1962);
    inv.add_books("The Road Back to You", "Ian Morgan Cron", 2016);
    inv.add_books("The Color Purple", "Alice Walker", 1982);
    inv.add_books("The Brothers Karamazov", "Fyodor Dostoevsky", 1880);
    inv.add_books("The Goldfinch", "Donna Tartt", 2013);
    inv.add_books("The Night Circus", "Erin Morgenstern", 2011);
    inv.add_books("The Help", "Kathryn Stockett", 2009);
    inv.add_books("The Shadow of the Wind", "Carlos Ruiz Zafón", 2001);
    inv.add_books("The Book Thief", "Markus Zusak", 2005);
    inv.add_books("The Adventures of Huckleberry Finn", "Mark Twain", 1884);
    inv.add_books("The Name of the Rose", "Umberto Eco", 1980);
    inv.add_books("The Secret History", "Donna Tartt", 1992);
    inv.add_books("The Giver", "Lois Lowry", 1993);
    inv.add_books("The Road to Oxiana", "Robert Byron", 1937);
    inv.add_books("The Fountainhead", "Ayn Rand", 1943);
    inv.add_books("The Inferno", "Dante Alighieri", 1320);
    inv.add_books("The Sense of an Ending", "Julian Barnes", 2011);
    inv.add_books("The Stand", "Stephen King", 1978);
    inv.add_books("The Tao of Pooh", "Benjamin Hoff", 1982);
    inv.add_books("The Stranger in the Woods", "Michael Finkel", 2017);
    inv.add_books("The Glass Menagerie", "Tennessee Williams", 1944);
    inv.add_books("The Ocean at the End of the Lane", "Neil Gaiman", 2013);
    inv.add_books("The Circle", "Dave Eggers", 2013);
    inv.add_books("The Rosie Project", "Graeme Simsion", 2013);
    inv.add_books("The Sympathizer", "Viet Thanh Nguyen", 2015);
    inv.add_books("The Secret History of Wonder Woman", "Jill Lepore", 2014);
    inv.add_books("The Book of Strange New Things", "Michel Faber", 2014);
    inv.add_books("The Silence of the Lambs", "Thomas Harris", 1988);
    inv.add_books("The Secret Adversary", "Agatha Christie", 1922);
    inv.add_books("The Nightingale", "Kristin Hannah", 2015);
    inv.add_books("The Vegetarian", "Han Kang", 2007);
    inv.add_books("The Glass Castle", "Jeannette Walls", 2005);
    inv.add_books("The Road to Character", "David Brooks", 2015);
    inv.add_books("The Distant Hours", "Kate Morton", 2010);
    inv.add_books("The Forgotten Garden", "Kate Morton", 2008);
    inv.add_books("The Thirteenth Tale", "Diane Setterfield", 2006);
    inv.add_books("The Angel's Game", "Carlos Ruiz Zafón", 2008);
    inv.add_books("The Miniaturist", "Jessie Burton", 2014);
    inv.add_books("The Night Watch", "Sarah Waters", 2006);
    inv.add_books("The Help", "Kathryn Stockett", 2009);
    inv.add_books("The Book Thief", "Markus Zusak", 2005);
    inv.add_books("The Sense of an Ending", "Julian Barnes", 2011);
    inv.add_books("The Rosie Project", "Graeme Simsion", 2013);

    inv.add_movies("Citizen Kane", "English", 1941);
    inv.add_movies("Seven Samurai", "Japanese", 1954);
    inv.add_movies("The Godfather", "English", 1972);
    inv.add_movies("The Shawshank Redemption", "English", 1994);
    inv.add_movies("Pulp Fiction", "English", 1994);
    inv.add_movies("Schindler's List", "English", 1993);
    inv.add_movies("Cinema Paradiso", "Italian", 1988);
    inv.add_movies("The Seventh Seal", "Swedish", 1957);
    inv.add_movies("Pan's Labyrinth", "Spanish", 2006);
    inv.add_movies("Spirited Away", "Japanese", 2001);
    inv.add_movies("Amélie", "French", 2001);
    inv.add_movies("Rashomon", "Japanese", 1950);
    inv.add_movies("Metropolis", "German", 1927);
    inv.add_movies("City of God", "Portuguese", 2002);
    inv.add_movies("The Lives of Others", "German", 2006);
    inv.add_movies("Oldboy", "Korean", 2003);
    inv.add_movies("The Grand Budapest Hotel", "English/French/German", 2014);
    inv.add_movies("A Separation", "Persian", 2011);
    inv.add_movies("The Great Beauty", "Italian", 2013);
    inv.add_movies("Roma", "Spanish/Mixtec", 2018);
    inv.add_movies("La La Land", "English", 2016);
    inv.add_movies("The Bicycle Thief", "Italian", 1948);
    inv.add_movies("Yojimbo", "Japanese", 1961);
    inv.add_movies("The Hunt", "Danish", 2012);
    inv.add_movies("Life Is Beautiful", "Italian", 1997);
    inv.add_movies("The Intouchables", "French", 2011);
    inv.add_movies("Ran", "Japanese", 1985);
    inv.add_movies("Goodfellas", "English", 1990);
    inv.add_movies("The Bridge on the River Kwai", "English", 1957);
    inv.add_movies("The 400 Blows", "French", 1959);
    inv.add_movies("Persona", "Swedish", 1966);
    inv.add_movies("The Handmaiden", "Korean", 2016);
    inv.add_movies("In the Mood for Love", "Cantonese", 2000);
    inv.add_movies("The Lives of Others", "German", 2006);
    inv.add_movies("The Farewell", "English/Mandarin", 2019);
    inv.add_movies("Memories of Murder", "Korean", 2003);
    inv.add_movies("Akira", "Japanese", 1988);
    inv.add_movies("Let the Right One In", "Swedish", 2008);
    inv.add_movies("Infernal Affairs", "Cantonese", 2002);
    inv.add_movies("Grave of the Fireflies", "Japanese", 1988);
    inv.add_movies("The Salesman", "Persian", 2016);
    inv.add_movies("Train to Busan", "Korean", 2016);
    inv.add_movies("Hero", "Mandarin", 2002);
    inv.add_movies("Das Boot", "German", 1981);
    inv.add_movies("The Lives of Others", "German", 2006);
    inv.add_movies("My Neighbor Totoro", "Japanese", 1988);
    inv.add_movies("Battle Royale", "Japanese", 2000);
    inv.add_movies("The Lives of Others", "German", 2006);
    inv.add_movies("Winter Sleep", "Turkish", 2014);
    inv.add_movies("Parasite", "Korean", 2019);
    inv.add_movies("Breathless", "French", 1960);
    inv.add_movies("Das Leben der Anderen (The Lives of Others)", "German", 2006);
    inv.add_movies("Crouching Tiger, Hidden Dragon", "Mandarin", 2000);
    inv.add_movies("A Man and a Woman", "French", 1966);
    inv.add_movies("Let the Bullets Fly", "Mandarin", 2010);
    inv.add_movies("The Secret in Their Eyes", "Spanish", 2009);
    inv.add_movies("Memories of Underdevelopment", "Spanish", 1968);
    inv.add_movies("Volver", "Spanish", 2006);
    inv.add_movies("8½", "Italian", 1963);
    inv.add_movies("Wild Strawberries", "Swedish", 1957);
    inv.add_movies("Farewell My Concubine", "Mandarin", 1993);
    inv.add_movies("The Spirit of the Beehive", "Spanish", 1973);
    inv.add_movies("The Sea Inside", "Spanish", 2004);
    inv.add_movies("Jean de Florette", "French", 1986);
    inv.add_movies("Manon of the Spring", "French", 1986);
    inv.add_movies("La Haine", "French", 1995);
    inv.add_movies("My Sassy Girl", "Korean", 2001);
    inv.add_movies("The Leopard", "Italian", 1963);
    inv.add_movies("Ip Man", "Cantonese", 2008);
    inv.add_movies("The Handmaiden", "Korean", 2016);
    inv.add_movies("The Diving Bell and the Butterfly", "French", 2007);
    inv.add_movies("Three Colors: Blue", "French", 1993);
    inv.add_movies("Three Colors: White", "French", 1994);
    inv.add_movies("Three Colors: Red", "French", 1994);
    inv.add_movies("Wings of Desire", "German", 1987);
    inv.add_movies("Cinema Paradiso", "Italian", 1988);
    inv.add_movies("The Hunt for Red October", "English", 1990);
    inv.add_movies("The Fencer", "Finnish", 2015);
    inv.add_movies("Like Father, Like Son", "Japanese", 2013);
    inv.add_movies("Hiroshima Mon Amour", "French", 1959);
    inv.add_movies("The Lives of Others", "German", 2006);
    inv.add_movies("La La Land", "English", 2016);
    inv.add_movies("Persepolis", "French", 2007);
    inv.add_movies("Pan's Labyrinth", "Spanish", 2006);
    inv.add_movies("Incendies", "French/Arabic", 2010);
    inv.add_movies("Dancer in the Dark", "Danish/English", 2000);
    inv.add_movies("El Laberinto del Fauno (Pan's Labyrinth)", "Spanish", 2006);
    inv.add_movies("The Wave", "German", 2008);
    inv.add_movies("In the Shadow of the Moon", "English", 2007);
    inv.add_movies("Mon oncle", "French", 1958);
    inv.add_movies("The Orphanage", "Spanish", 2007); 
    inv.add_movies("The Celebration", "Danish", 1998);
    inv.add_movies("Amour", "French", 2012);
    inv.add_movies("The Chorus", "French", 2004);
    inv.add_movies("Kontroll", "Hungarian", 2003);
    inv.add_movies("Y Tu Mamá También", "Spanish", 2001);
    inv.add_movies("The best of Youth", "Italian", 2003);
    inv.add_movies("Shoplifters", "Japanese", 2018);
    inv.add_movies("The Avengers", "English", 2012);
    inv.add_movies("Avengers: Age of Ultronm", "English", 2015);

    inv.list_options();
    cin >> choice;
    cout <<endl << endl;
    while(choice != 3)
    {
        if(choice == 1)
        {
            inv.list_books();
            inv.search_book();
        }
        else if (choice == 2)
        {
            inv.list_movies();
            inv.search_movie();
        }
        else
        {
            cout << "Invalid choice!" <<endl;
        }
        cout << endl;
        inv.list_options();
        cin >> choice;
    }
    // inv.search_book("It starts with us.");
    return 0;
}
