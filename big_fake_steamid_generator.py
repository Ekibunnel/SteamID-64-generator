steamid = bin(int(input("enter steamid64\n")))
steamid32 = str(steamid[-32:])
max_mod = "00000001000111111111111111111111"
print("steamid : "+steamid)
print("steamid32 : "+steamid32)
#print("max_mod : "+max_mod)
max_fake_steamid64 = max_mod+steamid32
#print("max_fake_steamid64 : "+max_fake_steamid64)
a_ton_of_nines = str(bin(int('9'*8167)))
#print("a_ton_of_nines : "+a_ton_of_nines)
end_of_a_ton_of_nines = a_ton_of_nines[-64:]
#print("end_of_a_ton_of_nines : "+end_of_a_ton_of_nines)
diff = int(end_of_a_ton_of_nines,2)^int(max_fake_steamid64,2)
#print("diff : "+bin(diff)+" : "+str(diff))
big_ass_fake_steamid64 = int(a_ton_of_nines,2)-diff
print("big_ass_fake_steamid64 : "+str(big_ass_fake_steamid64))