function read_solar_system,fdata,n_steps

 n_planets = 0L

 open,1,fdata
 readu,1,n_planets

 print,"N_planets = ", n_planets

 ;data array

s = {n_planets:0L,n_steps:0L,a_semi:dblarr(n_planets),e:dblarr(n_planets),t:dblarr(n_steps), dt:dblarr(n_steps),istep:lonarr(n_steps),x:dblarr(2,n_planets,n_steps),v:dblarr(2,n_planets,n_steps),a:dblarr(2,n_planets,n_steps), pstep:lonarr(n_planets,n_steps), pt:dblarr(n_planets,n_steps), pdt:dblarr(n_planets,n_steps)}


 s.n_planets = n_planets
 s.n_steps = n_steps

 ;read initial semi major axes and eccentricities

 a = 0.0D
 e = 0.0D

 for j=0, n_planets-1 do begin
  readu,1,a
  s.a_semi(j) = a
 endfor

 for j=0,n_planets-1 do begin
  readu,1,e
  s.e(j) = e
   ; print,j,s.a_semi(j),s.e(j)
 endfor

 ;loop over steps annd planets

 for i=0,n_steps-1 do begin
  istep = 0L
  t = 0.0D
  dt = 0.0D
  readu,1,istep
  readu,1,t
  readu,1,dt

  ;print, isetep,t,dt

  s.istep(i) = istep
  s.t(i)     = t
  s.dt(i)    = dt


  istep = 0L
  t = 0.0D
  dt = 0.0D
  x = dblarr(2)
  v = dblarr(2)
  ag = dblarr(2)



 for j=0,n_plaents-1 do begin
  readu,1,istep
  readu,1,t
  readu,1,dt
  readu,1,x
  readu,1,v
  readu,1,ag
  s.pstep(j,i) = istep
  s.pt(j,i) = t
  s.dt(j,i) = dt
  s.x(*,j.i) = x(*)
  s.v(*,j,i) = v(*)
  s.ag(*,j,i) = ag(*)

  ;print,istep,t,dt,x(0),x(1),v(0),v(1),ag(0),ag(1)
  endfor
 endfor

  close,1
  return, s
end