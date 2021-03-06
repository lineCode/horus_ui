#pragma once
#include "horus.h"
#include "horus_interfaces.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_version.h>
#include <vector>

namespace hui
{
struct SdlSettings
{
    Utf8StringBuffer mainWindowTitle;
    Rect mainWindowRect;
    WindowPositionType positionType = WindowPositionType::Undefined;
    bool vSync = true;
    void* sdlContext = nullptr;
    SDL_Window* sdlMainWindow = nullptr;
    GraphicsProvider* gfxProvider = nullptr;
};

struct Sdl2InputProvider : InputProvider
{
	Sdl2InputProvider();
	~Sdl2InputProvider();
	void startTextInput(Window window, const Rect& imeRect) override;
	void stopTextInput() override;
	bool copyToClipboard(Utf8String text) override;
	bool pasteFromClipboard(Utf8String *outText) override;
	void processEvents() override;
	void setCurrentWindow(Window window) override;
	Window getCurrentWindow() override;
	Window getFocusedWindow() override;
	Window getHoveredWindow() override;
	Window getMainWindow() override;
	Window createWindow(
		Utf8String title, i32 width, i32 height,
		WindowBorder border = WindowBorder::Resizable,
		WindowPositionType windowPos = WindowPositionType::Undefined,
		Point customPosition = { 0, 0 },
		bool showInTaskBar = true) override;
	void setWindowTitle(Window window, Utf8String title) override;
	void setWindowRect(Window window, const Rect& rect) override;
	Rect getWindowRect(Window window) override;
	void presentWindow(Window window) override;
	void destroyWindow(Window window) override;
	void showWindow(Window window) override;
	void hideWindow(Window window) override;
	void raiseWindow(Window window) override;
	void maximizeWindow(Window window) override;
	void minimizeWindow(Window window) override;
	WindowState getWindowState(Window window) override;
	void setCapture(Window window) override;
	void releaseCapture() override;
	Point getMousePosition() override;
	bool mustQuit() override;
	bool wantsToQuit() override;
	void cancelQuitApplication() override;
	void quitApplication() override;
	void shutdown() override;
	void setCursor(MouseCursorType type) override;
	MouseCursor createCustomCursor(Rgba32* pixels, u32 width, u32 height, u32 hotX, u32 hotY) override;
	void destroyCustomCursor(MouseCursor cursor) override;
	void setCustomCursor(MouseCursor cursor) override;
	void updateDeltaTime();
	f32 getDeltaTime() const;

	KeyCode fromSdlKey(int code);
	void addSdlEvent(SDL_Event& ev);
	void processSdlEvents();

	bool quitApp = false;
	bool addedMouseMove = false;
	bool wantsToQuitApp = false;
	SDL_GLContext sdlOpenGLCtx;
	SDL_Window* mainWindow = nullptr;
	SDL_Window* focusedWindow = nullptr;
	SDL_Window* hoveredWindow = nullptr;
	SDL_Window* currentWindow = nullptr;
	Context context = nullptr;
	u32 lastTime = SDL_GetTicks();
	f32 deltaTime = 0;
	bool sizeChanged = false;
	SDL_Cursor *cursors[SDL_NUM_SYSTEM_CURSORS] = {nullptr};
	std::vector<SDL_Cursor*> customCursors;
	std::vector<SDL_Surface*> customCursorSurfaces;
    GraphicsProvider* gfxProvider = nullptr;
};

void initializeWithSDL(const SdlSettings& settings);

}
