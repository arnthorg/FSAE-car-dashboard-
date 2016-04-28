format short
format compact

fclose(instrfind);
 s = serial('COM8');
 set(s, 'Baudrate',115200);
 fopen(s);
pause(2);
fprintf(s, '%c10','a');
% out  = String.empty(5,1);
out2 = NaN;

for i = 1:256
    value = fscanf(s, '%s',16);
    if length(value)>1
        disp(value)
    else
        disp('couldnt read')
    end
end
%% 
fclose(instrfind);
delete(s);
clear s