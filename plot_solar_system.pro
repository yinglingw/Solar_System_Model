fdata = "solar_system.dat"

n_steps = 731
s = read_solar_system(fdata,n_steps)

pcolor = fltarr(s.n_planets)
pcolor(0) = 255 ;mercury
pcolor(1) = 40  ;venus
pcolor(2) = 140 ;earth

pr = flatrr(s.n_planets)
pr(0) = 0.01
pr(1) = 0.03
pr(2) = 0.04

fdir = 'plots/'
set_plot, 'ps'

for i=0, n_steps-1 do begin

 exts = get_exts(i,d=4)
 fname = fdir+'orbit.'+exts+'.eps'

 device,filename=fname,/encapsulated,/color,bits=8

 device,xsize=5,ysize=5,/inches

 bkg = fltarr(100,100)
 bkg(*,*) = 0
 tvscl,bkg,0,0,xsize=1,ysize=1,/normal

 plot,[0],[0],xrange=[-1.1,1.1],yrange=[-1.1,1.1],xstyle=5,ystyle=5,position=[0,0,1,1],/normal,/noerase

 ;plot the sun
 theta = 2*!pi*findgen(100)/99.

 rsun=0.1
 loadct,13,/silent
 polyfill,rsun*cos(theta),rsun*sin(theta),/fill,color=220
 loadct,0,/silent

  for k=0,s.n_planets-1 do begin
  
   if i gt 0 then begin
    oplot,s.x(0,k,0:i),s.x(1,k,0:i),thick=3,color=255
    loadct,13,/silent
    polyfill,s.x(0,k,i)+pr(k)*cos(theta), s.x(1,k,i)+pr(k)*sin(theta),/fill,color=pcolor(k)
    loadct,0,/silent

   endif else begin

    loadct,13,/silent
    polyfill,s.x(0,k,i)+pr(k)*cos(theta), s.x(1,k,i)+pr(k)*sin(theta),/fill,color=pcolor(k)
    loadct,0,/silent
   endelse
  endfor

 device,/close
endfor  

 set_plot,'x'

end
