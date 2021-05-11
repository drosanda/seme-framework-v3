#!/bin/bash
export SONAR_TOKEN="5c7d3d55dd105fa07894d6c7ed57f017188838bd"
echo SONAR_TOKEN
sonar-scanner -Dsonar.organization=drosanda -Dsonar.projectKey=drosanda_seme-framework-v3 -Dsonar.sources=. -Dsonar.host.url=https://sonarcloud.io
