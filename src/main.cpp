#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <array>
#include "injector/injector.hpp"

const char* minigamesel_page = "minigamesel2.cgf";
const char* img_minimass1 = "career/minimass1.tga";
const char* img_minimass2 = "career/minimass2.tga";

const char* btnMassDestruction1_Name = "btnMassDestruction1";
uintptr_t btnMassDestruction1_Ptr;
const char* btnMassDestruction2_Name = "btnMassDestruction2";
uintptr_t btnMassDestruction2_Ptr;

void __declspec(naked) PreloadImages()
{
	__asm
	{
		call sub_5E4D20

		mov edx, img_minimass1
		mov eax, ds: [0x7CF700]
		push 0
		call sub_5E4D20

		mov edx, img_minimass2
		mov eax, ds: [0x7CF700]
		push 0
		call sub_5E4D20

		jmp loc_549C85

	loc_549C85:
		push 0x549C85
		retn

	sub_5E4D20:
		push 0x5E4D20
		retn
	}
}

void __declspec(naked) ElemsDeclr()
{
	__asm
	{
		call sub_6959C9
		
		// declaring the UI elements
	
		mov ebx, -1
		mov edx, dword ptr [btnMassDestruction1_Name]
		lea eax, [esp + 0x200]
		call sub_69586C
		mov edx, eax
		mov eax, ecx
		call sub_49B170
		mov ds: [btnMassDestruction1_Ptr], eax
		xor edx, edx
		lea eax, [esp + 0x200]
		call sub_6959C9
			
		mov ebx, -1
		mov edx, dword ptr [btnMassDestruction2_Name]
		lea eax, [esp + 0x210]
		call sub_69586C
		mov edx, eax
		mov eax, ecx
		call sub_49B170
		mov ds: [btnMassDestruction2_Ptr], eax
		xor edx, edx
		lea eax, [esp + 0x210]
		call sub_6959C9
			
		// assigning the functions to the UI elements

		mov ebx, -1
		mov edx, dword ptr [btnMassDestruction1_Name]
		lea eax, [esp + 0x220]
		call sub_69586C
		mov ebx, btnMassDestruction1_Func
		mov edx, eax
		mov eax, ecx
		call sub_4A0410
		mov ds: [btnMassDestruction1_Ptr], eax
		xor edx, edx
		lea eax, [esp + 0x220]
		call sub_6959C9
		
		mov ebx, -1
		mov edx, dword ptr [btnMassDestruction2_Name]
		lea eax, [esp + 0x230]
		call sub_69586C
		mov ebx, btnMassDestruction2_Func
		mov edx, eax
		mov eax, ecx
		call sub_4A0410
		mov ds: [btnMassDestruction2_Ptr], eax
		xor edx, edx
		lea eax, [esp + 0x230]
		call sub_6959C9

		jmp loc_549BF5

	btnMassDestruction1_Func:
		cmp dl, 03
		je loc_54A0C1

		cmp dl, 04
		je md1_run

		retn

	md1_run:
		mov eax, 6
		call sub_5484E0
		retn

	btnMassDestruction2_Func:
		cmp dl, 03
		je md2_check

		cmp dl, 04
		je md2_run

		retn

	md2_check:
		mov eax,ds: [0x7EA2CC]
		mov edx, 28	// completed missions count to unlock (incl. tutorial events)
		mov eax,[eax+0xC]
		call sub_68D7E0
		mov al, [eax + 0xE1]	// 0xE0 - is available?, 0xE1 - is passed?
		test al,al
		je finish
		call sub_549330
		retn

	finish:
		retn

	md2_run:
		mov eax, 7
		call sub_5484E0
		retn

	sub_68D7E0:
		push 0x68D7E0
		retn

	sub_549330:
		push 0x549330
		retn

	sub_5484E0:
		push 0x5484E0
		retn

	loc_54A0C1:
		push 0x54A0C1
		retn

	sub_695AA9:
		push 0x695AA9
		retn

	sub_695DB9:
		push 0x695DB9
		retn

	sub_69586C:
		push 0x69586C
		retn

	sub_6959C9:
		push 0x6959C9
		retn

	sub_49B170:
		push 0x49B170
		retn

	loc_549BF5:
		push 0x549BF5
		retn

	sub_4A0410:
		push 0x4A0410
		retn

	sub_52CE50:
		push 0x52CE50
		retn

	sub_539A0F:
		push 0x539A0F
		retn

	sub_4AF990:
		push 0x4AF990
		retn

	sub_672700:
		push 0x672700
		retn

	sub_5E4D20:
		push 0x5E4D20
		retn
	}
}

const char* gamevar_minimass = "minigame-maxdestruction";
const char* gamevar_minimass_full = "gamevar=minigame-maxdestruction";

const char* trk_md1 = "minigame/mini_mass_1.trk";
const char* trk_md2 = "minigame/mini_mass_2.trk";

void __declspec(naked) MD_Load()
{
	__asm
	{
		cmp esi, 06
		je md1
		cmp esi, 07
		je md2
		cmp esi, 05
		ja loc_5485DC
		jmp loc_54853C

	md1:
		mov edx,img_minimass1
		mov eax,esp
		mov ebx,-1
		call sub_695A15
		mov edx, ds: [gamevar_minimass_full]
		lea eax,[esp+0xA0]
		xor ecx,ecx
		call sub_69586C
		mov edx,7
		mov ebx,eax
		lea eax,[esp+0xB0]
		call sub_485E10
		mov edx,eax
		lea eax,[esp+0x10]
		call sub_695F1D
		lea eax,[esp+0xB0]
		xor edx,edx
		call sub_6959C9
		lea eax,[esp+0xA0]
		xor edx,edx
		mov ebx,-1
		call sub_6959C9
		mov edx,trk_md1
		lea eax,[esp+0x160]
		call sub_69586C
		mov ecx,ds: [0x7EA2CC]
		mov edx,5	// position in the high scores file
		mov ecx,[ecx+0x10]
		mov ebx,eax
		mov eax,ecx
		call sub_68D9D0
		lea eax,[esp+0x160]
		jmp loc_5485D5

	md2:
		mov edx,img_minimass2
		mov eax,esp
		mov ebx,-1
		call sub_695A15
		mov edx, ds: [gamevar_minimass_full]
		lea eax,[esp+0xA0]
		xor ecx,ecx
		call sub_69586C
		mov edx,7
		mov ebx,eax
		lea eax,[esp+0xB0]
		call sub_485E10
		mov edx,eax
		lea eax,[esp+0x10]
		call sub_695F1D
		lea eax,[esp+0xB0]
		xor edx,edx
		call sub_6959C9
		lea eax,[esp+0xA0]
		xor edx,edx
		mov ebx,-1
		call sub_6959C9
		mov edx,trk_md2
		lea eax,[esp+0x160]
		call sub_69586C
		mov ecx,ds: [0x7EA2CC]
		mov edx,5	// position in the high scores file
		mov ecx,[ecx+0x10]
		mov ebx,eax
		mov eax,ecx
		call sub_68D9D0
		lea eax,[esp+0x160]
		jmp loc_5485D5


	loc_5485D5:
		push 0x5485D5
		retn

	sub_68D9D0:
		push 0x68D9D0
		retn

	sub_6959C9:
		push 0x6959C9
		retn

	sub_695F1D:
		push 0x695F1D
		retn

	sub_485E10:
		push 0x485E10
		retn

	sub_69586C:
		push 0x69586C
		retn

	sub_695A15:
		push 0x695A15
		retn

	loc_5485DC:
		push 0x5485DC
		retn

	loc_54853C:
		push 0x54853C
		retn
	}
}

void __declspec(naked) MD_Visual()
{
	__asm
	{
		cmp esi, 06	// MD 1
		je md1

		cmp esi, 07	// MD 2
		je md2

	end:
		push 0x43660000
		jmp loc_5485FE

	md1:
		mov al, 1
		jmp end

	md2:
		mov eax,ds: [0x7EA2CC]
		mov edx,28	// completed missions count to unlock (incl. tutorial events)
		mov eax,[eax+0xC]
		call sub_68D7E0
		mov al,[eax+0xE1]	// 0xE0 - is available?, 0xE1 - is passed?
		jmp end

	sub_68D7E0:
		push 0x68D7E0

	sub_6959C9:
		push 0x6959C9
		retn

	loc_548997:
		push 0x548997
		retn

	loc_5485FE:
		push 0x5485FE
		retn
	}
}

const char* event_md1 = "minigamemass1.txt";
const char* event_md2 = "minigamemass2.txt";

void __declspec(naked) MD_LoadEventFile()
{
	__asm
	{
		mov eax, ds: [0x78D65C]
		lea edx, [esp + 0x12C]
		call sub_4A4A00
		call sub_4976B0
		mov edx, dword ptr [btnMassDestruction1_Name]
		call sub_696058
		test eax, eax
		setne bl
		xor edx, edx
		lea eax, [esp + 0x012C]
		call sub_6959C9
		test bl, bl
		jne md1_file

		mov eax, ds: [0x78D65C]
		lea edx, [esp + 0x12C]
		call sub_4A4A00
		call sub_4976B0
		mov edx, dword ptr [btnMassDestruction2_Name]
		call sub_696058
		test eax, eax
		setne bl
		xor edx, edx
		lea eax, [esp + 0x012C]
		call sub_6959C9
		test bl, bl
		jne md2_file

		jmp loc_54942B

	md1_file:
		mov edx, event_md1
		jmp loc_54941F

	md2_file:
		mov edx, event_md2
		jmp loc_54941F

		jmp loc_54942B

	sub_4A4A00:
		push 0x4A4A00
		retn

	sub_4976B0:
		push 0x4976B0
		retn

	sub_696058:
		push 0x696058
		retn

	sub_6959C9:
		push 0x6959C9
		retn

	loc_54941F:
		push 0x54941F
		retn

	loc_54942B:
		push 0x54942B
		retn
	}
}

void __declspec(naked) MD_Check()
{
	__asm
	{
		mov edx, trk_md1
		lea eax, [esp + 0x2E0]
		call sub_696058
		test eax, eax
		je md2
		mov ecx, 6
		jmp loc_543CB4

	md2:
		mov edx, trk_md2
		lea eax, [esp + 0x2E0]
		call sub_696058
		test eax, eax
		je end
		mov ecx, 7
		jmp loc_543CB4

	end:
		mov edx, 0x6D110C
		jmp loc_543E8B

	loc_543E8B:
		push 0x543E8B
		retn

	sub_696058:
		push 0x696058
		retn

	loc_543CB4:
		push 0x543CB4
		retn
	}
}

void __declspec(naked) MD_Check2()
{
	__asm
	{
		mov ds: [0x70EB60], ecx

		cmp ecx, 06
		je md1

		cmp ecx, 07
		je md2

		jmp loc_543CBA

	md1:
		mov edx, img_minimass1
		lea eax,[esp+0x40]
		mov ebx,-1
		call sub_695A15
		mov edx, gamevar_minimass_full
		lea eax,[esp+0x140]
		xor ecx,ecx
		call sub_69586C
		mov edx,7
		mov ebx,eax
		lea eax,[esp+0x150]
		call sub_485E10
		mov edx,eax
		lea eax,[esp+0x50]
		call sub_695F1D
		lea eax,[esp+0x150]
		xor edx,edx
		call sub_6959C9
		lea eax,[esp+0x140]
		jmp loc_543D23

	md2:
		mov edx, img_minimass2
		lea eax,[esp+0x40]
		mov ebx,-1
		call sub_695A15
		mov edx, gamevar_minimass_full
		lea eax,[esp+0x140]
		xor ecx,ecx
		call sub_69586C
		mov edx,7
		mov ebx,eax
		lea eax,[esp+0x150]
		call sub_485E10
		mov edx,eax
		lea eax,[esp+0x50]
		call sub_695F1D
		lea eax,[esp+0x150]
		xor edx,edx
		call sub_6959C9
		lea eax,[esp+0x140]
		jmp loc_543D23

	loc_543CBA:
		push 0x543CBA
		retn

	loc_543D23:
		push 0x543D23
		retn

	sub_6959C9:
		push 0x6959C9
		retn

	sub_695F1D:
		push 0x695F1D
		retn

	sub_695A15:
		push 0x695A15
		retn

	sub_69586C:
		push 0x69586C
		retn

	sub_485E10:
		push 0x485E10
		retn
	}
}

const char* md_gametips_section = "gametips/minigamemass";

void __declspec(naked) MD_GameTips()
{
	__asm
	{
		cmp ebx, 06
		je load_gametips
		cmp ebx, 07
		je load_gametips

		jmp loc_545FE5

	load_gametips:
		mov edx, md_gametips_section
		jmp loc_545EDA

	loc_545FE5:
		push 0x545FE5
		retn

	loc_545EDA:
		push 0x545EDA
		retn
	}
}

void __declspec(naked) MD_ResultCheck()
{
	__asm
	{
		mov edx, trk_md1
		mov eax, edi
		call sub_696058
		test eax, eax
		je md2
		mov esi, 6
		jmp loc_56E627

	md2:
		mov edx, trk_md2
		mov eax, edi
		call sub_696058
		test eax, eax
		je end
		mov esi, 7
		jmp loc_56E627

	end:
		push 0x1AA
		jmp loc_56E8B8

	loc_56E8B8:
		push 0x56E8B8
		retn

	loc_56E627:
		push 0x56E627
		retn

	sub_696058:
		push 0x696058
		retn
	}
}

const char* md_result_key = "DESTROYEDOBJECTS";
const char* md_result_section = "MassDestruction.Results";

const char* md_score_key = "MAINVALUEMINIMASS";
const char* md_score_section = "gametext/hud.txt";

void __declspec(naked) MD_ResultCheck2()
{
	__asm
	{
		je loc_56ED84

		cmp esi, 6
		je md
		cmp esi, 7
		je md

		jmp loc_56E723

	md:
		mov ebx, md_result_key
		mov edx, md_result_section
		mov eax,ds: [0x7E3110]
		call sub_66F410
		mov ebx,-1
		mov edx,eax
		lea eax,[esp+0x280]
		call sub_69586C
		mov edx,eax
		mov eax,0x7A8618
		call sub_695F1D
		lea eax,[esp+0x280]
		xor edx,edx
		mov ebx, md_score_key
		call sub_6959C9
		mov edx, md_score_section
		mov eax,ds: [0x7E3110]
		call sub_66F410
		mov ebx,-1
		mov edx,eax
		lea eax,[esp+0x220]
		call sub_69586C
		mov edx,eax
		mov eax,0x7A8628
		call sub_695F1D
		lea eax,[esp+0x220]
		jmp loc_56E7BE

	loc_56E7BE:
		push 0x56E7BE
		retn

	sub_6959C9:
		push 0x6959C9
		retn

	sub_695F1D:
		push 0x695F1D
		retn

	sub_69586C:
		push 0x69586C
		retn

	sub_66F410:
		push 0x66F410
		retn

	loc_56ED84:
		push 0x56ED84
		retn

	loc_56E723:
		push 0x56E723
		retn
	}
}

const char* md_inferface_section = "MassDestruction.Interface";

const char* md1_btn_key = "btnMassDestruction1.Caption";
const char* md2_btn_key = "btnMassDestruction2.Caption";

void __declspec(naked) MD_ResultCheck3()
{
	__asm
	{
		call sub_69598E

		cmp esi, 6
		je md1
		cmp esi, 7
		je md2

		jmp loc_56E637

	md1:
		mov ebx, md1_btn_key
		mov edx, md_inferface_section
		mov eax,ds: [0x7E3110]
		call sub_66F410
		mov ebx,-1
		mov edx,eax
		lea eax,[esp+0x150]
		call sub_69586C
		mov edx,eax
		lea eax,[esp+0x10]
		call sub_695F1D
		lea eax,[esp+0x150]
		xor edx,edx
		mov ebx,-1
		call sub_6959C9
		mov edx,gamevar_minimass_full
		lea eax,[esp+0x160]
		xor ecx,ecx
		call sub_69586C
		mov edx,7
		mov ebx,eax
		lea eax,[esp+0x170]
		call sub_485E10
		mov edx,eax
		mov eax,esp
		call sub_695F1D
		lea eax,[esp+0x170]
		xor edx,edx
		call sub_6959C9
		lea eax,[esp+0x160]
		xor edx,edx
		mov ebx,-1
		call sub_6959C9
		mov edx,trk_md1
		lea eax,[esp+0x180]
		call sub_69586C
		mov edi,ds: [0x7EA2CC]
		mov edx,5	// position in the high scores file
		mov edi,[edi+0x10]
		mov ebx,eax
		mov eax,edi
		call sub_68D9D0
		lea eax,[esp+0x180]
		jmp loc_56E70B

	md2:
		mov ebx, md2_btn_key
		mov edx, md_inferface_section
		mov eax,ds: [0x7E3110]
		call sub_66F410
		mov ebx,-1
		mov edx,eax
		lea eax,[esp+0x150]
		call sub_69586C
		mov edx,eax
		lea eax,[esp+0x10]
		call sub_695F1D
		lea eax,[esp+0x150]
		xor edx,edx
		mov ebx,-1
		call sub_6959C9
		mov edx,gamevar_minimass_full
		lea eax,[esp+0x160]
		xor ecx,ecx
		call sub_69586C
		mov edx,7
		mov ebx,eax
		lea eax,[esp+0x170]
		call sub_485E10
		mov edx,eax
		mov eax,esp
		call sub_695F1D
		lea eax,[esp+0x170]
		xor edx,edx
		call sub_6959C9
		lea eax,[esp+0x160]
		xor edx,edx
		mov ebx,-1
		call sub_6959C9
		mov edx,trk_md2
		lea eax,[esp+0x180]
		call sub_69586C
		mov edi,ds: [0x7EA2CC]
		mov edx,5	// position in the high scores file
		mov edi,[edi+0x10]
		mov ebx,eax
		mov eax,edi
		call sub_68D9D0
		lea eax,[esp+0x180]
		jmp loc_56E70B

	loc_56E70B:
		push 0x56E70B
		retn

	sub_68D9D0:
		push 0x68D9D0
		retn

	sub_485E10:
		push 0x485E10
		retn

	sub_6959C9:
		push 0x6959C9
		retn

	sub_695F1D:
		push 0x695F1D
		retn

	sub_69586C:
		push 0x69586C
		retn

	sub_66F410:
		push 0x66F410
		retn

	sub_69598E:
		push 0x69598E
		retn

	loc_56E637:
		push 0x56E637
		retn
	}
}

void __declspec(naked) MD2_ToggleBtnStyles()
{
	__asm
	{
		mov eax,ds: [0x7EA2CC]
		mov edx,28	// completed missions count to unlock (incl. tutorial events)
		mov eax,[eax+0xC]
		call sub_68D7E0
		mov al,[eax+0xE1]	// 0xE0 - is available?, 0xE1 - is passed?
		
		test al,al
		je btn_unavailable

		mov edx, 0xC7C7C7
		jmp end

	btn_unavailable:
		mov edx, 0x585858
		jmp end

	end:
		mov eax, ds: [btnMassDestruction2_Ptr]
		call sub_4975C0
		lea edx,[esp+0x160]
		jmp loc_549D19

	loc_549D19:
		push 0x549D19
		retn

	sub_4975C0:
		push 0x4975C0
		retn

	sub_68D7E0:
		push 0x68D7E0
		retn
	}
}

void __declspec(naked) ElemsDeclr2()
{
	__asm
	{
		call sub_5E6CE0

		mov edx, img_minimass1
		mov eax, ds: [0x7CF700]
		call sub_5E6CE0

		mov edx, img_minimass2
		mov eax, ds: [0x7CF700]
		call sub_5E6CE0

		jmp loc_5495C1

	loc_5495C1:
		push 0x5495C1
		retn

	sub_5E6CE0:
		push 0x5E6CE0
		retn
	}
}

void __declspec(naked) ElemsDeclr3()
{
	__asm
	{
		call sub_5E4D20

		mov edx, img_minimass1
		mov eax, ds: [0x7CF700]
		push 0
		call sub_5E4D20

		mov edx, img_minimass2
		mov eax, ds: [0x7CF700]
		push 0
		call sub_5E4D20

		jmp loc_548A94

	sub_5E4D20:
		push 0x5E4D20
		retn

	loc_548A94:
		push 0x548A94
		retn
	}
}

const char* minigame_maps[] =
{
  "mini_jump_1.trk",
  "mini_blast_1.trk",
  "mini_chase_1.trk",
  "mini_mass_1.trk",
  "mini_jump_2.trk",
  "mini_blast_2.trk",
  "mini_chase_2.trk",
  "mini_mass_2.trk"
};	// an array for forbidding overwriting of mini-game maps 

void __declspec(naked) InvincibilityForMiniGames()
{
	__asm
	{
		mov eax, ds: [0x78D5F0]
		cmp byte ptr [eax + 0x60], 16	// minigame_longjump
		je loc_441394
		cmp byte ptr [eax + 0x60], 18	// minigame_checkpointchase
		je loc_441394
		cmp byte ptr [eax + 0x60], 19	// minigame_maxdestruction
		je loc_441394

	falsecond:
		mov eax,[esp+0x10]
		mov [ecx+0x6EBC],eax

	loc_441394:
		push 0x441394
		retn
	}
}

void Init()
{
    injector::WriteMemory(0x547FDF, minigamesel_page, true);
    injector::WriteMemory(0x56F45F, minigamesel_page, true);

	injector::MakeJMP(0x549C80, PreloadImages, true);
	injector::MakeJMP(0x549BF0, ElemsDeclr, true);
	injector::MakeJMP(0x5495BC, ElemsDeclr2, true);
	injector::MakeJMP(0x548A8F, ElemsDeclr3, true);
	injector::MakeJMP(0x549D12, MD2_ToggleBtnStyles, true);
	injector::MakeJMP(0x548533, MD_Load, true);
	injector::MakeJMP(0x5485F9, MD_Visual, true);
	injector::MakeJMP(0x5497CA, MD_LoadEventFile, true);
	injector::MakeJMP(0x543E86, MD_Check, true);
	injector::MakeJMP(0x543CB4, MD_Check2, true);
	injector::MakeJMP(0x545FE0, MD_GameTips, true);
	injector::MakeJMP(0x56E8B3, MD_ResultCheck, true);
	injector::MakeJMP(0x56E71D, MD_ResultCheck2, true);
	injector::MakeJMP(0x56E632, MD_ResultCheck3, true);

	injector::WriteMemory(0x549836, 0x300, true);
	injector::WriteMemory(0x549DD6, 0x300, true);

	injector::MakeNOP(0x5484F7, 6, true);

	injector::WriteMemory(0x485CAB, minigame_maps, true);
	injector::WriteMemory<BYTE>(0x485CBD, std::size(minigame_maps) * 4, true);

	injector::MakeJMP(0x44138A, InvincibilityForMiniGames, true);
}

DWORD WINAPI MainTHREAD(LPVOID)
{
	Init();
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		if (*(DWORD*)0x4000A8 == 0x29BB90)	// Checking the entry point of 1.2 executable
		{
			CreateThread(0, 0, MainTHREAD, 0, 0, 0);
		}
		else
			return FALSE;
	}

	return TRUE;
}
