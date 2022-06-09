# refactor
def check_valid_col(n, col, columns, rows):
    if col[1] == 0 or col in rows or (col[0]-1, col[1]) in rows or (col[0], col[1]-1) in columns:
        return True
    return False

def check_valid_row(r, columns, rows):
    if ((r[0],r[1]-1) in columns or (r[0]+1,r[1]-1) in columns) or ((r[0]+1, r[1]) in rows and (r[0]-1, r[1]) in rows):
        return True
    return False

def check_all_valid(n, columns, rows):
    for column in columns:
        if check_valid_col(n, column, columns, rows) == False:
            return False
    for row in rows:
        if check_valid_row(row, columns, rows) == False:
            return False  
    return True
            
def solution(n, build_frame):
    cols = []
    rows = []
    
    for frame in build_frame:
        # 삭제하는 경우
        if frame[3] == 0:
            # 제거 후 조건에 맞지 않다면 다시 넣음
            if (frame[2] == 0):
                cols.remove((frame[0], frame[1]))
                if check_all_valid(n, cols, rows) == False:
                    cols.append((frame[0], frame[1]))
            else:
                rows.remove((frame[0], frame[1]))
                if check_all_valid(n, cols, rows) == False:
                    rows.append((frame[0], frame[1]))
        # 추가하는 경우
        else:
            # 조건에 맞다면 추가
            if (frame[2] == 0):
                if check_valid_col(n, (frame[0], frame[1]), cols, rows) == True:
                    cols.append((frame[0], frame[1]))
            else:
                if check_valid_row((frame[0], frame[1]), cols, rows) == True:
                    rows.append((frame[0], frame[1]))
                    
    result = []
    for col in cols:
        result.append([col[0], col[1], 0])
    for row in rows:
        result.append([row[0], row[1], 1])

    return sorted(result, key=lambda x:(x[0], x[1], x[2]))

'''
# raw
def format_build_frame(build_frame, n):
    for frame in build_frame:
        i = n - frame[1]
        j = frame[0]
        frame[0] = i
        frame[1] = j
    return build_frame

def format_to_result(n, x, y, type):
    return [y, n-x, type]

def check_valid_col(n, col, columns, rows):
    if col[0] == n:
        return True
    for row in rows:
        if col == row or (col[0] == row[0] and col[1] == row[1] + 1):
            return True
    for column in columns:
        if col[0] == column[0] - 1 and col[1] == column[1]:
            return True
    return False

def check_valid_row(r, columns, rows):
    for column in columns:
        if (r[0] == column[0]-1 and r[1] == column[1]) or (r[0] == column[0]-1 and r[1] == column[1]-1):
            return True
    
    chk = 0
    for row in rows:
        if (r[0] == row[0] and r[1] == row[1] + 1) or (r[0] == row[0] and r[1] == row[1] - 1):
            chk += 1
    if (chk == 2):
        return True
    return False

def check_all_valid(n, columns, rows):
    for column in columns:
        if check_valid_col(n, column, columns, rows) == False:
            return False
    for row in rows:
        if check_valid_row(row, columns, rows) == False:
            return False  
    return True
            
def solution(n, build_frame):
    # 배열 좌표로 변환
    formatted_frames = format_build_frame(build_frame, n)
    
    cols = [] # 기둥
    rows = [] # 보
    
    for frame in formatted_frames:
        # 삭제하는 경우
        if frame[3] == 0:
            # 제거 후 조건에 맞지 않다면 다시 넣음
            if (frame[2] == 0):
                cols.remove((frame[0], frame[1]))
                if check_all_valid(n, cols, rows) == False:
                    cols.append((frame[0], frame[1]))
            else:
                rows.remove((frame[0], frame[1]))
                if check_all_valid(n, cols, rows) == False:
                    rows.append((frame[0], frame[1]))
        # 추가하는 경우
        else:
            # 조건에 맞다면 추가
            if (frame[2] == 0):
                if check_valid_col(n, (frame[0], frame[1]), cols, rows) == True:
                    cols.append((frame[0], frame[1]))
            else:
                if check_valid_row((frame[0], frame[1]), cols, rows) == True:
                    rows.append((frame[0], frame[1]))
        
    result = []
    for col in cols:
        result.append(format_to_result(n, col[0], col[1], 0))
    for row in rows:
        result.append(format_to_result(n, row[0], row[1], 1))

    result = sorted(result, key=lambda x:(x[0], x[1], x[2]))
    
    return result
'''
