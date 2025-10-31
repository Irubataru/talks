# Local dev environment for the Academy Platform

- Title: Local dev environment for the Academy Platform
- Event: op:ignite
- Date: 2025-10-24
- Made with Figma presentation

## Abstract

I spent last summer making a purely local development environment for the
Academy Platform team. The Academy Platform has a microservice architecture, and
it was previously impossible to run it locally due to numerous inter-dependent
services and Azure integrations. This led to a frustrating development
experience where developers only found out if their changes broke any of the
integration tests after a 10 minute pipeline, with no way of investigating or
debug errors locally.

During the summer, I containerized each service and created mocked or emulated
instances of every external dependency: from Sessionize to the Entra Graph API.
The result was a dev environment that developers could spin up on their computer
and run and debug at will.

In this talk, I will outline the challenges faced by the Academy team and
present the work I did to alleviate these issues. I hope to emphasize how
essential good development experiences are for keeping developers productive,
happy, and sane.
