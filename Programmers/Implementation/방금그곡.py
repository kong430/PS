'''
C, C#, D, D#, E, F, F#, G, G#, A, A#, B => 총 12개
1분에 하나씩 음 재생, 반드시 처음부터 재생.
if 음악 길이 < 재생 시간: 반복 재생
else 음악 길이 >= 재생 시간: 재생 시간만큼만 재생
-> 조건 일치하는 음악 여러개면, 재생시간 가장 긴 음악 제목 반환
    단, 가장 긴 음악이 여러개일 경우 먼저 입력된 제목 반환
-> 없으면 "(None)"
'''
def cal_time(start, end):
    start_h, start_m = start.split(':')
    end_h, end_m = end.split(':')
    return (int(end_h)-int(start_h))*60+int(end_m)-int(start_m)

def solution(m, musicinfos):
    # m: 음(문자열)
    # musicinfos: 곡 정보(문자열) 배열, 시작시각,끝시각,제목,악보정보
    musics = [] # (재생 시간, 제목, idx)
    substitues = {'C#':'c', 'D#':'d', 'F#':'f', 'G#':'g', 'A#': 'a'}
    cnt = 0
    for s in substitues:
        m = m.replace(s, substitues[s])
    for music in musicinfos:
        start, end, title, mel = music.split(',')
        for s in substitues:
            mel = mel.replace(s, substitues[s])
        time = cal_time(start, end)
        played = mel*(time//len(mel))+mel[:time%len(mel)]
        if m in played:
            musics.append((time, title, cnt))
            cnt += 1
    
    if len(musics)==0:
        return "(None)"
    if len(musics)==1:
        return musics[0][1]
    
    musics.sort(key=lambda x:(x[0], -x[2]), reverse=True)
    return musics[0][1]
