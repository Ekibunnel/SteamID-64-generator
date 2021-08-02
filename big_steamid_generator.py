patern_list = ["9", "69", "420", "1337"]

steamid = bin(int(input("enter steamid64\n")))
steamid32 = str(steamid[-32:])
max_mod = "00000001000111111111111111111111"
print("steamid : "+steamid)
print("steamid32 : "+steamid32)
#print("max_mod : "+max_mod)
max_fake_steamid64 = int(max_mod+steamid32,2)
#print("max_fake_steamid64 : "+max_fake_steamid64)

def longsteamIDgenerator(patern, steamID):
    big_patern = bin(int(str(int(patern*8167))[:8167]))
    #print("big_patern : "+big_patern)
    end_of_big_patern = int(big_patern[-64:],2)
    #print("end_of_big_patern : "+str(end_of_big_patern))
    big_ass_fake_steamid64 = (int(big_patern,2)-end_of_big_patern)+steamID
    print("Long SteamID #"+patern+" : "+str(big_ass_fake_steamid64))

for i in patern_list:
    longsteamIDgenerator(i, max_fake_steamid64)
