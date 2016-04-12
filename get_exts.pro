function get_exts,num,d=d

if not keyword_set(d) then d = 3

if num lt 1000 then begin
	exts = ''
	for i=0,d do exts=exts+'0'
	exts=exts+strcompress(string(num),/remove_all) ; sets exts to snap number
	exts=strmid(exts,strlen(exts)-d,d)
endif else begin

	if num lt 10000 then begin
		if d lt 4 then d = 4
		exts = ''
		for i=0,d do exts=exts+'0'
		exts=exts+strcompress(string(num),/remove_all) ; sets exts to snap number
		exts=strmid(exts,strlen(exts)-d,d)
	endif else begin
		if num lt 100000 then begin
			if d lt 5 then d = 5
			exts = ''
			for i=0,d do exts=exts+'0'
			exts=exts+strcompress(string(num),/remove_all) ; sets exts to snap number
			exts=strmid(exts,strlen(exts)-d,d)
		endif else begin
			if d lt 6 then d = 6
			exts = ''
			for i=0,d do exts=exts+'0'
			exts=exts+strcompress(string(num),/remove_all) ; sets exts to snap number
			exts=strmid(exts,strlen(exts)-d,d)
		endelse
	endelse
endelse
return,exts
end