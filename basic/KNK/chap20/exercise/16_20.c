typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
union {
	struct {
		DWORD eax, ebx, ecx, edx;
	} dword;

	struct {
		WORD ax, hax, bx, hbx;
		WORD cx, hcx, dx, hdx;
	} word;

	struct {
		BYTE al, ah, hal, hah, bl, bh, hbl, hbh;
		BYTE cl, ch, hcl, hch, dl, dh, hdl, hdh;
	} byte;
} regs_32;
