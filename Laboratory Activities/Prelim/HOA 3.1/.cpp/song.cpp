#include <iostream>
#include <string>

using namespace std;

// Node for each song
struct Song
{
    string title;
    Song* next;
    Song* prev;

    Song(string songTitle)
    {
        title = songTitle;
        next = nullptr;
        prev = nullptr;
    }
};

class Playlist
{
private:
    Song* head;

public:
    Playlist()
    {
        head = nullptr;
    }

    // Add a song to the end of the playlist
    void addSong(string title)
    {
        Song* newSong = new Song(title);

        if (head == nullptr)
        {
            head = newSong;
            newSong->next = newSong;
            newSong->prev = newSong;
            return;
        }

        Song* last = head->prev;

        last->next = newSong;
        newSong->prev = last;
        newSong->next = head;
        head->prev = newSong;
    }

    // Remove a song from the playlist
    void removeSong(string title)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* current = head;

        do
        {
            if (current->title == title)
            {
                if (current->next == current)
                {
                    head = nullptr;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;

                    if (current == head)
                        head = current->next;
                }

                cout << "\"" << title << "\" was removed.\n";
                delete current;
                return;
            }

            current = current->next;

        } while (current != head);

        cout << "\"" << title << "\" was not found.\n";
    }

    // Display all songs once
    void playAll()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* current = head;

        cout << "\nPlaylist:\n";

        do
        {
            cout << "- " << current->title << endl;
            current = current->next;

        } while (current != head);
    }

    Song* getHead()
    {
        return head;
    }

    Song* nextSong(Song* current)
    {
        return current->next;
    }

    Song* previousSong(Song* current)
    {
        return current->prev;
    }
};

int main()
{
    Playlist playlist;

    // Create playlist
    playlist.addSong("Lifetime - Ben&Ben");
    playlist.addSong("Aura - IV OF SPADES");
    playlist.addSong("Saan? - Maki");
    playlist.addSong("711 - TONEEJAY");

    cout << "Original Playlist";
    playlist.playAll();

    // Add a new song
    cout << "\nAdding \"Seasons - w2e\"...\n";
    playlist.addSong("Seasons - w2e");
    playlist.playAll();

    // Remove a song
    cout << "\nRemoving \"Aura - IV OF SPADES\"...\n";
    playlist.removeSong("Aura - IV OF SPADES");
    playlist.playAll();

    // Demonstrate next and previous
    Song* current = playlist.getHead();

    cout << "\nCurrent Song: " << current->title << endl;

    current = playlist.nextSong(current);
    cout << "Next Song: " << current->title << endl;

    current = playlist.previousSong(current);
    cout << "Previous Song: " << current->title << endl;

    return 0;
}