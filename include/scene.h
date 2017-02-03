typedef struct {
	void (*start)(void);
	void (*update)(void);
	void (*exit)(void);
} Scene;
