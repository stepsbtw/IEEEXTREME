import math

def mmc(a, b):
    return abs(a * b) // math.gcd(a, b)

def contar_azulejo(N, elasticidades, idx=0, mmc_atual=1, tam_sub=0):
    if mmc_atual > N:
        return 0

    if idx == len(elasticidades):
        if tam_sub == 0:  
            return 0
        multiplos = N // mmc_atual
        return multiplos if tam_sub % 2 == 1 else -multiplos

    return contar_azulejo(N, elasticidades, idx + 1, mmc_atual, tam_sub) + contar_azulejo(N, elasticidades, idx + 1, mmc(mmc_atual, elasticidades[idx]), tam_sub + 1)

def solution(N, elasticidades):
    return contar_azulejo(N, elasticidades)

N, K = map(int, input().split())
elasticidades = list(set(map(int, input().split())))

print(solution(N, elasticidades))
