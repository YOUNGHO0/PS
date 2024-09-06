def solution(scores):
    answer = 0
    target_a, target_b = scores[0]
    target_score = target_a + target_b

    # 첫번째 점수에 대해서 내림차순,
    # 첫 번째 점수가 같으면 두 번째 점수에 대해서 오름차순으로 정렬합니다.
    scores.sort(key=lambda x: (-x[0], x[1]))
    maxb = 0
    
    for a, b in scores:
        if target_a < a and target_b < b:
            return -1
        
        if b >= maxb:
            maxb = b
            if a + b > target_score:
                answer += 1
            
    return answer + 1