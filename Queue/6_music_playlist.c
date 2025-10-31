#include <stdio.h>
#define MAX 100

typedef struct {
    int songs[MAX];
    int front, rear, size;
    int current_pos;
} MusicPlaylist;

void init(MusicPlaylist *p) {
    p->front = 0;
    p->rear = -1;
    p->size = 0;
    p->current_pos = -1;
}

int isEmpty(MusicPlaylist *p) {
    return p->size == 0;
}

void addSong(MusicPlaylist *p, int song_ID) {
    if (p->size < MAX) {
        p->rear = (p->rear + 1) % MAX;
        p->songs[p->rear] = song_ID;
        p->size++;
        printf("Added song %d\n", song_ID);
    }
}

int playSong(MusicPlaylist *p) {
    if (isEmpty(p)) {
        printf("No songs in playlist!\n");
        return -1;
    }
    int played = p->songs[p->front];
    p->front = (p->front + 1) % MAX;
    p->size--;
    p->current_pos = 0;
    printf("Playing song %d\n", played);
    return played;
}

void nextSong(MusicPlaylist *p) {
    if (isEmpty(p)) {
        printf("No songs!\n");
        return;
    }
    p->current_pos = (p->current_pos + 1) % p->size;
    int next = p->songs[(p->front + p->current_pos) % MAX];
    printf("Next song: %d\n", next);
}

void previousSong(MusicPlaylist *p) {
    if (isEmpty(p)) {
        printf("No songs!\n");
        return;
    }
    p->current_pos = (p->current_pos - 1 + p->size) % p->size;
    int prev = p->songs[(p->front + p->current_pos) % MAX];
    printf("Previous song: %d\n", prev);
}

void displayPlaylist(MusicPlaylist *p) {
    if (isEmpty(p)) {
        printf("Playlist is empty\n");
        return;
    }
    printf("Playlist: ");
    for (int i = 0; i < p->size; i++) {
        printf("%d ", p->songs[(p->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    MusicPlaylist p;
    init(&p);
    int choice, song;
    
    while (1) {
        printf("\n1. Add song\n2. Play song\n3. Next song\n4. Previous song\n5. Display playlist\n6. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter song ID: ");
                scanf("%d", &song);
                addSong(&p, song);
                break;
            case 2:
                playSong(&p);
                break;
            case 3:
                nextSong(&p);
                break;
            case 4:
                previousSong(&p);
                break;
            case 5:
                displayPlaylist(&p);
                break;
            case 6:
                return 0;
        }
    }
}
