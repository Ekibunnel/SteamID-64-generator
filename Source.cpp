#include <iostream>
#include <fstream>  
using namespace std;
#include <string>
#include <bitset>

#include <windows.h>

std::bitset<32> OSteamBase = 17825793;
// Original steam base for steamID 64
//  00000001000100000000000000000001

unsigned long long  MaxBitsMod = 1048575;
// Max bit modification to be a valide SteamID 64
//  11111111111111111111

unsigned long long OriginalSteam; // original steamID 64
std::bitset<64> SteamBits; // original steamID 64 in Bits
std::bitset<32> BaseSteam; // Base of the original steamID 64 if any
std::bitset<32> SteamID32; // SteamID 32 found in OriginalSteam
unsigned long long RealSteam64; // The real steamID 64, based on the original steam base for steamID 64 and the SteamID 32
unsigned long long Index = 0; // Index used to generate steamID 64

unsigned long long BitsetAddition(std::bitset<32> Base, std::bitset<32> SID32) {
	return ((std::bitset<64>(Base.to_ullong()) << 32) | std::bitset<64>(SID32.to_ullong())).to_ullong();
}

int main()
{
	SetConsoleTitle("SteamID 64 Generator");
	cout << "Original SteamID (32/64) : ";
	cin >> OriginalSteam;
	SteamBits = std::bitset<64>(OriginalSteam);
	SteamID32 = ((SteamBits << 32) >> 32).to_ulong();
	BaseSteam = (SteamBits >> 32).to_ulong();
	cout << "SteamID 32 : " << SteamID32 << endl;
	if (BaseSteam.any()) {
		cout << "SteamID 64 : " << SteamBits << endl;
		cout << "SteamID 64 BASE : " << BaseSteam << endl;
		if (BaseSteam != OSteamBase)
		{
			if (7 - MessageBox(NULL, "Do you want generate new steamID 64 from there ?", "SteamID 64 BASE NOT COMMON", MB_YESNO))
			{
				Index = ((BaseSteam << 12) >> 12).to_ullong();
			}
		}
	}
	RealSteam64 = BitsetAddition(OSteamBase, SteamID32);
	std::ofstream outfile("STEAMID64.txt", ios::app);
	outfile << std::dec << "#	| SteamID 64 : " << RealSteam64 << std::endl << "#	| SteamID 32 : " << SteamID32.to_ullong() << std::endl;
	cout << std::endl << "Loading";
	for (int i = Index; i <= MaxBitsMod; i++)
	{
		if ((i%(MaxBitsMod/10)) == 0)
		{
			cout << ".";
		}
		std::bitset<32> GenerateSteamBase = i;
		GenerateSteamBase[20] = 1;
		GenerateSteamBase[24] = 1;
		outfile << std::dec << i << "	| " << BitsetAddition(GenerateSteamBase, SteamID32) << endl;
	}
	outfile.close();



	cout << std::endl << std::endl << "Process Finished" << endl << endl;
	system("pause");
	return 0;
}