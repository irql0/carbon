

//0xFFE1E1E1 fill
//0xFFADADAD border

#include "driver.h"
#include "wnd.h"

VOID
NtGdiDiButtonWndProc(
	__in PKWINDOW Window,
	__in ULONG32 Message,
	__in ULONG32 Param1,
	__in ULONG32 Param2
)
{
	Window;
	Message;
	Param1;
	Param2;

	switch ( Message ) {
	case WM_MOUSE_CLICK:

		//KdCmdMessage( L"%s recieved mouse click.", Window->Name.Buffer );

		Window->Parent->Class->WndProc( Window->Parent, WM_COMMAND, Window->MenuId, 0 );
		break;
	default:
		break;
	}

}

VOID
NtGdiDiButtonClassInit(
	__in PKWINDOW Window,
	__in PWNDCLASSEX Class
)
{

	PDI_BUTTON Button = NtGdiAllocateDi( DI_BUTTON );

	Button->Base.DrawProcedure = ( DI_DRAW_PROCEDURE )NtGdiDiButtonDrawProc;
	Button->Base.DiFlink = NULL;

	Button->Border = Class->Border;
	Button->Fill = Class->Fill;

	NtGdiDiInsert( Window, ( PDI_BASE )Button );

}

VOID
NtGdiDiButtonDrawProc(
	__in PKWINDOW Window,
	__in PDI_BUTTON Button
)
{
	ULONG32 Width = Window->Rect.right - Window->Rect.left;
	ULONG32 Height = Window->Rect.bottom - Window->Rect.top;

	for ( ULONG32 i = 0; i < ( Width * Height ); i++ ) {

		Window->PrimaryBuffer[ i ] = Button->Fill;
	}

	if ( g_Focus != Window ) {

		for ( ULONG32 i = 0; i < Width; i++ ) {

			Window->PrimaryBuffer[ i ] = Button->Border;
		}

		for ( ULONG32 i = 0; i < Width; i++ ) {

			Window->PrimaryBuffer[ ( Height - 1 ) * Width + i ] = Button->Border;
		}

		for ( ULONG32 i = 0; i < Height; i++ ) {

			Window->PrimaryBuffer[ Width * i ] = Button->Border;
		}

		for ( ULONG32 i = 0; i < Height; i++ ) {

			Window->PrimaryBuffer[ Width * ( i + 1 ) - 1 ] = Button->Border;
		}
	}
	else {

		for ( ULONG32 i = 0; i < ( Width * 2 ); i++ ) {

			Window->PrimaryBuffer[ i ] = 0xFF0078D7;
		}

		for ( ULONG32 i = 0; i < ( Width * 2 ); i++ ) {

			Window->PrimaryBuffer[ ( Height - 2 ) * Width + i ] = 0xFF0078D7;
		}

		for ( ULONG32 i = 0; i < ( Height * 2 ); i++ ) {

			Window->PrimaryBuffer[ ( Width * ( i % Height ) ) + ( i / Height ) ] = 0xFF0078D7;
		}

		for ( ULONG32 i = 0; i < ( Height * 2 ); i++ ) {

			Window->PrimaryBuffer[ ( Width * ( ( i % Height ) + 1 ) ) - 2 + ( i / Height ) ] = 0xFF0078D7;
		}


	}

	POINT BufferRegion = { Width, Height };

	RECT Rect;
	Rect.top = 4;
	Rect.left = 4;
	Rect.bottom = Height - Rect.top;
	Rect.right = Width - Rect.left;

	NtGdiRenderText( Window->PrimaryBuffer, &Window->Name, &Rect, &BufferRegion );

}
