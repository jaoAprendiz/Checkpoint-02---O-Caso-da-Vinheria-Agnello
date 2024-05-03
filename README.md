# Checkpoint-02---O-Caso-da-Vinheria-Agnello
<img src="circuitoCompleto.png">
<p>Projeto desenvolvido como parte da atividade de Edge Computing e Computer Systems na <a href="">FIAP</a> ministrada pelo professor <a href="https://www.linkedin.com/in/fabio-cabrini?miniProfileUrn=urn%3Ali%3Afs_miniProfile%3AACoAAA4IttQBKDdr5cvPzUTzpVSkZFkQM-qKngk&lipi=urn%3Ali%3Apage%3Ad_flagship3_search_srp_all%3B3UXPOnpXR6qTOU9g%2FnseBQ%3D%3D" target="_blank">Fábio Cabrini</a>.</p>
<p>Este projeto consiste em um sistema de alarme desenvolvido no Tinkercad para monitorar a luminosidade do ambiente de uma vinheria. O objetivo é oferecer uma solução simples e eficaz para a vinheria (empresa fictícia) que deseja ampliar seu mercado através do serviço de delivery de vinhos.</p>
<strong>Link do circuíto no Tinkercad: <a href="https://wokwi.com/projects/396235203544314881">Checkpoint 02 - O Caso da Vinheria Agnello</a></strong>

<h2>Integrantes: </h2>
<ol>
  <li>
    <p>João Victor Soave</p>
    <a href="https://github.com/siigAprendiz"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
  </li>
  <li>
    <p>Felipe Nascimento</p>
    <a href="https://github.com/felipe3103"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
  </li>
    <li>
    <p>Henrique Ignacio</p>
    <a href="https://github.com/henriqueignacio"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
  </li>
    <li>
    <p>Gustavo</p>
    <a><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
  </li>
</ol>

<h2>Contexto e Descrição do Desafio</h2>
<p>Vocês foram contratados pela Vinheria Agnello para desenvolver um sistema de monitoramento a ser instalado 
no ambiente em que os vinhos são armazenados. O dono a Vinheria informou que a qualidade do vinho é 
influenciada diretamente pelas condições de temperatura, umidade e luminosidade do ambiente. Neste 
primeiro momento, você propôs ao dono da Vinheria um projeto em etapas, de modo que seu 1° desafio é:</p>
<ul>
  <li>Elaborar um sistema usando Arduino que faça a captura das informações de luminosidade do ambiente. Para 
isso pesquise sobre o LDR e sobre conversores analógico para digital do Arduino. Verifique como eles 
funcionam e como poderiam ser usados no projeto.</li>
  <li>De posse dos dados coletados, implemente um sistema de alarme, utilizando LEDs, para sinalizar quando o a 
ambiente estiver OK, ou quando alguma grandeza estiver fora dos limites estipulados. Use um LED verde 
para indicar que está OK, um LED amarelo para indica que está em níveis de alerta e um LED Vermelho para 
indicar que tem algum problema.</li>
  <li>Quando a luminosidade estiver em nível de alerta, deve soar uma buzina (buzzer) por 3 segundos. A buzina 
volta a soar caso a luminosidade permaneça em nível de alerta.</li>
</ul>

<h2>Descrição: </h2>
<p>O sistema de alarme é composto por um Arduino, um sensor de luminosidade (LDR), três LEDs e um buzzer. O Arduino monitora continuamente a luminosidade ambiente usando o sensor de luminosidade. O nível de luminosidade é mostrado através dos LEDs, considerando que o nível ideal de luminosidade para o armazenamento de vinhos é baixo (abaixo de 30%). Em caso de níveis de luminosidade de alerta (entre 30% e 60%), o LED amarelo será aceso e caso o nível seja crítico (acima de 60%) será aceso o LED vermelho e o buzzer emitirá um som de perigo durante 3 segundos.</p>

## Dependências

- **Wokwi**: Plataforma de simulação de hardware que permite prototipar circuitos eletrônicos e sistemas embarcados online.
- **Componentes Virtuais**: Sensores virtuais de luminosidade, temperatura e umidade disponíveis na plataforma Wokwi.

## Como Reproduzir

1. Acesse o [Wokwi](https://wokwi.com/).
2. Abra o projeto "Checkpoint 02 - O Caso da Vinheria Agnello" (ou crie um novo projeto).
3. Adicione os componentes virtuais de sensor de luminosidade, temperatura e umidade ao projeto.
4. Conecte os componentes de acordo com o diagrama do circuito.
5. Carregue o código do Arduino que realiza a leitura dos sensores e simula o controle das condições ideais para armazenamento de vinhos.
6. Execute a simulação para observar o comportamento do sistema.

## Funcionalidades

- Leitura em tempo real da luminosidade, temperatura e umidade do ambiente.
- Simulação de controle para manter as condições ideais de armazenamento de vinhos.
- Visualização dos dados de monitoramento em um display virtual.

<!-- <h2>Funcionamento: </h2>
<p>Luminosidade OK: </p>
<img src="img/testeOk.png" alt="Teste OK">
<p>Luminosidade Alerta: </p>
<img src="img/testeAlerta.png" alt="Teste Alerta">
<p>Luminosidade Perigo: </p>
<img src="img/testePerigo.png" alt="Teste Perigo">
<p>Código no Tinkercad</p>
<img src="img/codigoTinkerCad.png" alt="Código Tinkercad">
<p>Registro Serial: </p>
<img src="img/SerialRegister.png" alt="Registro Serial"> -->



