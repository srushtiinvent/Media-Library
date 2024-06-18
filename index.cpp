#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MediaItem {
public:
    MediaItem(const string& title, const string& creator, int releaseYear)
        : title(title), creator(creator), releaseYear(releaseYear) {}

    string getTitle() const {
        return title;
    }

    string getCreator() const {
        return creator;
    }

    int getReleaseYear() const {
        return releaseYear;
    }

    void setTitle(const string& newTitle) {
        title = newTitle;
    }

    void setCreator(const string& newCreator) {
        creator = newCreator;
    }

    void setReleaseYear(int newReleaseYear) {
        releaseYear = newReleaseYear;
    }

private:
    string title;
    string creator;
    int releaseYear;
};

class Book : public MediaItem {
public:
    Book(const string& title, const string& author, int releaseYear, int numPages)
        : MediaItem(title, author, releaseYear), numPages(numPages) {}

    int getNumPages() const {
        return numPages;
    }

    void setNumPages(int newNumPages) {
        numPages = newNumPages;
    }

private:
    int numPages;
};

class Movie : public MediaItem {
public:
    Movie(const string& title, const string& director, int releaseYear, int durationMinutes)
        : MediaItem(title, director, releaseYear), durationMinutes(durationMinutes) {}

    int getDurationMinutes() const {
        return durationMinutes;
    }

    void setDurationMinutes(int newDurationMinutes) {
        durationMinutes = newDurationMinutes;
    }

private:
    int durationMinutes;
};

class MusicAlbum : public MediaItem {
public:
    MusicAlbum(const string& title, const string& artist, int releaseYear, int numTracks)
        : MediaItem(title, artist, releaseYear), numTracks(numTracks) {}

    int getNumTracks() const {
        return numTracks;
    }

    void setNumTracks(int newNumTracks) {
        numTracks = newNumTracks;
    }

private:
    int numTracks;
};

class Library {
public:
    void addMediaItem(const MediaItem& item) {
        mediaItems.push_back(item);
    }

    void displayMediaItemDetails() const {
        for (const MediaItem& item : mediaItems) {
            cout << "Title: " << item.getTitle() << endl;
            cout << "Creator: " << item.getCreator() << endl;
            cout << "Release Year: " << item.getReleaseYear() << endl;
            cout << "-----------------------------------" << endl;
        }
    }

private:
    vector<MediaItem> mediaItems;
};

int main() {
    Library library;

    while (true) {
        int choice;
        cout << "Choose media type to add (1 - Book, 2 - Movie, 3 - Music Album, 4 - Quit): ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 4) {
            break;
        }

        string title, creator;
        int releaseYear;

        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter creator: ";
        getline(cin, creator);

        cout << "Enter release year: ";
        cin >> releaseYear;

        if (choice == 1) {
            int numPages;
            cout << "Enter number of pages: ";
            cin >> numPages;
            library.addMediaItem(Book(title, creator, releaseYear, numPages));
        } else if (choice == 2) {
            int durationMinutes;
            cout << "Enter duration (in minutes): ";
            cin >> durationMinutes;
            library.addMediaItem(Movie(title, creator, releaseYear, durationMinutes));
        } else if (choice == 3) {
            int numTracks;
            cout << "Enter number of tracks: ";
            cin >> numTracks;
            library.addMediaItem(MusicAlbum(title, creator, releaseYear, numTracks));
        }
    }

    cout << "Media Library Contents:" << endl;
    library.displayMediaItemDetails();

    return 0;
}


